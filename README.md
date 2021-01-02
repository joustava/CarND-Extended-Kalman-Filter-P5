# Extended Kalman Filter Project

> C++ project which is a solution to the Extended Kalman Filter project of Udacity's Self Driving Car Engineer Nano Degree. This document covers how the project has been setup.

## Prerequisites

! Read the whole readme through first

- [cmake version 3.19.1 installation](https://cmake.org/install/)
- [SDCE Term 2 simulator](https://github.com/udacity/self-driving-car-sim/releases)

## Build and Run

In the root directory run

```bash
cmake -S . -B build -DEigen3_DIR=(pwd)/extern/eigen/cmake
cmake --build build
```

then either run executable

```bash
./bin/KalmanExtended_APP
```

or tests (needs build of test target)

```bash
# Is this needed? cmake --build build --target test
./bin/KalmanExtended_LIB_TESTS
```

## Dependencies

- [Eigen](https://eigen.tuxfamily.org/dox-devel/index.html) as 'production' dependency
- [Catch2](https://github.com/catchorg/Catch2.git) as testing/development dependency

Eigen was added to the project by using `git submodule add https://gitlab.com/libeigen/eigen.git <external>` and then adding required config to `CMakeLists.txt`. See running section for making it available to build step.

The adding of [submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) after cloning is typically done once with `git submodule update --init` ran from the project root directory.

[Catch2](https://github.com/catchorg/Catch2.git) is fetched automatically via the configuration supplied in `tests/CMakeLists.txt`

## Contributing

We follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) as close as possible and use [clang-format](https://clang.llvm.org/docs/ClangFormat.html) to validate our code accordingly.

Tests live in `./tests` folder and we aim to not reduce coverage so please add tests for your code or changes.

## Resources

- [Kalman Filter tutorial](https://www.kalmanfilter.net/)
- [Kalman FIlter Wikipedia](https://en.wikipedia.org/wiki/Kalman_filter)
- [CMake dependency handling](https://foonathan.net/2016/07/cmake-dependency-handling/)
- [CMake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Eigen and CMake](http://eigen.tuxfamily.org/dox/TopicCMakeGuide.html)
- [Eigen tutorial](https://dritchie.github.io/csci2240/assignments/eigen_tutorial.pdf)
- [Mac, wchar issue](https://mhmethun.wordpress.com/2018/11/23/how-to-fix-c-cwchar-fatal-error-wchar-h-no-such-file-or-directory/)
- [Unit testing harness](https://wingman-sw.com/articles/tdd-legacy-c)
- [Doxygen](https://www.doxygen.nl/manual/docblocks.html)
- [BDD Style testing with Catch2](http://www.electronvector.com/blog/using-catch-to-write-bdd-style-unit-tests-for-c)