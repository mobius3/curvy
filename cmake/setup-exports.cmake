include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# Setup install of exported targets
install(EXPORT curvy-targets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/curvy
  NAMESPACE curvy::
)

# Macro to write config
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/curvy-config-version.cmake"
  VERSION ${curvy_VERSION}
  COMPATIBILITY SameMajorVersion
)

# Setup install of version config
install(
  FILES
    cmake/curvy-config.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/curvy-config-version.cmake"
  DESTINATION
   ${CMAKE_INSTALL_LIBDIR}/cmake/curvy
  COMPONENT "Curvy Development"
)
