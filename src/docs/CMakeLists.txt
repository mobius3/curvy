find_package(Doxygen QUIET)
find_package(Sphinx QUIET)

if (NOT DOXYGEN_FOUND)
  message(STATUS "Doxygen was not found. Docs will not be built.")
  return()
endif()

if (NOT SPHINX_FOUND)
  message(STATUS "Sphinx was not found. Docs will not be built.")
  return()
endif()

get_target_property(CURVY_DOCS_HEADERS curvy PUBLIC_HEADER)

# Doxygen stuff
set(CURVY_DOCS_INPUT ${CMAKE_CURRENT_LIST_DIR}/../../include)
set(CURVY_DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
set(CURVY_DOXYGEN_INDEX ${CURVY_DOXYGEN_OUT}/xml/index.xml)
set(CURVY_DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(CURVY_DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

configure_file(${CURVY_DOXYFILE_IN} ${CURVY_DOXYFILE_OUT} @ONLY)
file(MAKE_DIRECTORY ${CURVY_DOXYGEN_OUT})

add_custom_command(OUTPUT ${CURVY_DOXYGEN_INDEX}
  DEPENDS ${CURVY_DOCS_HEADERS}
  COMMAND ${DOXYGEN_EXECUTABLE} ${CURVY_DOXYFILE_OUT}
  MAIN_DEPENDENCY ${CURVY_DOXYFILE_OUT} ${CURVY_DOXYFILE_IN}
  COMMENT "Generating doxygen files")

add_custom_target(doxygen ALL DEPENDS ${CURVY_DOXYGEN_INDEX})

# Sphinx stuff
set(CURVY_SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR})
set(CURVY_SPHINX_OUT ${CMAKE_CURRENT_BINARY_DIR}/html)
set(CURVY_SPHINX_INDEX ${CURVY_SPHINX_OUT}/index.html)

add_custom_command(OUTPUT ${CURVY_SPHINX_INDEX}
  COMMAND
    ${SPHINX_EXECUTABLE} -b html
    -Dbreathe_projects.curvy=${CURVY_DOXYGEN_OUT}/xml
    ${CURVY_SPHINX_SOURCE} ${CURVY_SPHINX_OUT}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS
    index.rst
    ${CURVY_DOXYGEN_INDEX}
  MAIN_DEPENDENCY ${CURVY_SPHINX_SOURCE}/conf.py
  COMMENT "Generating HTML docs with Sphinx")

add_custom_target(sphinx ALL DEPENDS ${CURVY_SPHINX_INDEX})
add_custom_target(api-docs ALL DEPENDS sphinx)

include (GNUInstallDirs)
install(DIRECTORY ${CURVY_SPHINX_OUT} DESTINATION ${CMAKE_INSTALL_DOCDIR})