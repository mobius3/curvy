# Curvy

Curvy is a C99 library that delivers a clear and straightforward
interpolation API, allowing developers to build fluid and creative
animations for their software.

It has:

- Small, clear and declarative-style APIs
- Many builtin easing functions
- Multi-point interpolation
- No external dependencies
- Zero allocations
- Tween stepping, seeking and jumping
- Support for step, seek and jump callbacks

#### Example

There are two main ways of creating a tween, either when initializing
the `cy_tween` struct or after by calling functions:

**Initialization:**
```c
struct cy_tween tween = {
  .from = 0,
  .to = {
     { .value = 100, .via = cy_linear, .during = 100 }
  }
}
```

**Declarative functions**:

```c
struct cy_tween tween = {}; /* IMPORTANT! */
cy_from(&tween, 0.0f); 
cy_to(&tween, 10.0f, cy_linear, 100);
```

Both are valid ways and result in the same behavior. You can add up to
32 target values (this number can be tweaked by defining
`CURVY_MAX_CONTROL_POINTS` to the desired number when compiling the
library)

 **++Important!++**

 Initializing the structure **is mandatory**. This means you can either
 use the empty-braces initializer (as above), or `memset` the struct to
 0\. Passing an uninitialized `struct cy_tween` to any function results
 in undefined behaviour.

## Integrating with your code

### Using pre-built releases

Download a pre-built release package suitable for your platform and
uncompress it somewhere you'll remember later (usually where you put
other development libraries). Let's assume you uncompressed curvy to
`/home/me/libs/curvy`.

**Using CMake**: If you're using CMake, specify the variable
`CMAKE_PREFIX_PATH` to point to it before running CMake in your project:

```shell script
cmake -DCMAKE_PREFIX_PATH=/home/me/libs
```

Afterwards you can use `find_package(Curvy)` and
`target_link_libraries(<your-executable> PUBLIC curvy)` to link
`<your-executable>` against curvy.

**Not using CMake**: Assuming you uncompressed Curvy to the same path as
above, you should configure your build system to look for include files
inside `/home/me/libs/curvy/include` and to look for shared objects to
link against inside `/home/me/libs/curvy/lib`. In case of Windows, you
should also point your linker to `curvy/bin` as well.

### Using a source release and CMake

Uncompress Curvy in a folder inside your project (e.g,
`your-project/third-party/curvy`) and then use
`add_subdirectory(third-party/curvy EXCLUDE_FROM_ALL)` to add the
library target. Afterwards you can use `find_package(Curvy)` and
`target_link_libraries(<your-executable> PUBLIC curvy)` to link
`<your-executable>` against curvy.

Compiling the `.c` files directly in your project is not recommended nor
supported.

## Compile from source

You'll need CMake installed and in your path and also capable of finding
you compiler and linker. Then, after checking out this repository:

```shell script
mkdir build/
cd build/
cmake ..
make
```