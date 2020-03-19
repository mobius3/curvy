Curvy
=====

Curvy is a C99 library that delivers a clear and straightforward
interpolation API, allowing developers to build fluid and creative
animations for their software.

It has:

- Small, clear and declarative-style APIs
- Many built-in easing functions
- Multi-point interpolation
- No external dependencies
- Zero allocations
- Tween stepping, seeking and jumping
- Support for step, seek and jump callbacks

Example
-------

There are two main ways of creating a tween, either when initializing
the :code:`cy_tween` struct or after by calling functions:

**Initialization:**

.. code-block:: cpp

    struct cy_tween tween = {
      .from = 0,
      .to = {
         { .value = 100, .via = cy_linear, .during = 100 }
      }
    }


**Declarative functions**:

.. code-block:: c

    struct cy_tween tween = {}; /* IMPORTANT! */
    cy_from(&tween, 0.0f);
    cy_to(&tween, 10.0f, cy_linear, 100);

Both are valid ways and result in the same behavior. You can add up to
32 target values (this number can be tweaked by defining
:code:`CURVY_MAX_CONTROL_POINTS` to the desired number when compiling the
library)

.. warning::
 **Important!**

 Initializing the structure **is mandatory**. This means you can either
 use the empty-braces initializer (as above), or :code:`memset` the struct to
 0\. Passing an uninitialized :code:`struct cy_tween` to any function results
 in undefined behaviour.

Integrating with your code
--------------------------

Using pre-built releases
~~~~~~~~~~~~~~~~~~~~~~~~

Download a pre-built release package suitable for your platform and
uncompress it somewhere you'll remember later (usually where you put
other development libraries). Let's assume you uncompressed curvy to
:code:`/home/me/libs/curvy`.

**Using CMake**: If you're using CMake, specify the variable
:code:`CMAKE_PREFIX_PATH` to point to it before running CMake in your project:

.. code-block:: sh

    cmake -DCMAKE_PREFIX_PATH=/home/me/libs


Afterwards you can use :code:`find_package(Curvy)` and
:code:`target_link_libraries(<your-executable> PUBLIC curvy)` to link
:code:`<your-executable>` against curvy.

**Not using CMake**: Assuming you uncompressed Curvy to the same path as
above, you should configure your build system to look for include files
inside :code:`/home/me/libs/curvy/include` and to look for shared objects to
link against inside :code:`/home/me/libs/curvy/lib`. In case of Windows, you
should also point your linker to :code:`curvy/bin` as well.

Using a source release and CMake
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Uncompress Curvy in a folder inside your project (e.g,
:code:`your-project/third-party/curvy`) and then use
:code:`add_subdirectory(third-party/curvy EXCLUDE_FROM_ALL)` to add the
library target. Afterwards you can use :code:`find_package(Curvy)` and
:code:`target_link_libraries(<your-executable> PUBLIC curvy)` to link
:code:`<your-executable>` against curvy.

Compiling the :code:`.c` files directly in your project is not recommended nor
supported.

Compile from source
-------------------

You'll need CMake installed and in your path and also capable of finding
you compiler and linker. Then, after checking out this repository:

.. code-block:: sh

    mkdir build/
    cd build/
    cmake ..
    make

Running tests
-------------

Curvy tests links against `Criterion <http://github.com/Snaipe/Criterion>`_ so you need it installed
in your system if you intend to execute tests. Please refer to it's
manual on how to install it.

To build test executables, you need to set the CMake variable
:code:`CURVY_ENABLE_TESTING` to true when running :code:`cmake`:

.. code-block:: sh

    cmake -DCURVY_BUILD_TESTS=true ...

To run the tests, execute the :code:`test` target.