This is an example project using CMake heavily based on https://cliutils.gitlab.io/modern-cmake/

The requirements are:

* CMake 3.19 or better
* A C++17 compatible compiler
* Git
* Doxygen (optional)

To configure:

```bash
cmake -S . -B build
```

Add `-GNinja` if you have Ninja.

To build:

```bash
cmake --build build
```

To test (`--target` can be written as `-t` in CMake 3.15+):

```bash
cmake --build build --target test
```

To build docs (requires Doxygen, output in `build/docs/html`):

```bash
cmake --build build --target docs
```

To use an IDE, such as Xcode:

```bash
cmake -S . -B xbuild -GXcode
cmake --open xbuild
```

The CMakeLists show off several useful design patters for CMake.

add submodules with
git submodule add ../../owner/repo.git extern/repo