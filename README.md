[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)
[![Build Status](https://travis-ci.org/coderbot92/cpp-projects.svg?branch=master)](https://travis-ci.org/coderbot92/cpp-projects)
[![Coverage Status](https://coveralls.io/repos/github/coderbot92/cpp-projects/badge.svg?branch=master)](https://coveralls.io/github/coderbot92/cpp-projects?branch=master)
[![Repo Type: projects](https://img.shields.io/badge/repo%20type-projects-yellowgreen.svg)](#c++-projects)
[![HitCount](http://hits.dwyl.io/coderbot92/cpp-projects.svg)](http://hits.dwyl.io/coderbot92/cpp-projects)
[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)
[![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/coderbot92/cpp-projects/blob/master/LICENCE)

# C++ Projects

Tools used in the project:

- [Google Tests](https://github.com/google/googletest)
- Use of [CMake](https://cmake.org/) for much easier compiling
- Code documentation with [Doxygen](http://www.stack.nl/~dimitri/doxygen/)
- Continuous testing with [Travis-CI](https://travis-ci.org/)
- Code coverage with [Coveralls.io](https://coveralls.io/)

## Installation Instructions

Note: Google Tests is the submodule of this project which means that this repo refers to it but does not clone it.
```
# First delete .gitmodules file and googletest folder in ./external/

cd external

git submodule add https://github.com/svn2github/googletest.git
```
- Make sure you have the necessary files that may be skipped during cloning i.e. .gitignore, .gitmodules and .travis.yml 
- Update the badge links in README after turning repo on in travis-ci and coveralls website
- Update the project name in CMakeLists.txt
- Make sure you have c++ compiler, doxygen and ccmake installed

``` bash
# update the list of available packages and their versions but installs/upgrade nothing
$ sudo apt-get update
# upgrades the installed packages to newer versions if the installed versions and versions on list do not match 
$ sudo apt-get upgrade

$ g++ --version
$ make -v
# package that installs g++, gcc and make (run only if you don't have these)
$ sudo apt-get install build-essential

$ cmake --version
# if cmake is not available
$ sudo apt-get install cmake

# install doxygen for documentation generation
$ sudo apt-get install doxygen

# install gui tool for cmake
$ sudo apt-get install cmake-curses-gui
```

## Structure
```
.
├── CMakeLists.txt, .travis.yml, Doxyfile.in, .gitignore, .gitmodules
├── external
│   └── googletest
├── app
│   └── main.cpp
├── include
│   └── Dummy.h
│   └── array
│       └── Array.h
├── src
│   └── Dummy.cpp
│   └── array
│        └── Array.cpp
└── tests
    ├── main.cpp
    └── Dummy_test.cpp
    └── array
        └── Array_test.cpp

```

## File Placements

- Sources in [src/](src/) (compiled to a static library `engine` by default)
- Header files in [include/](include/)
- Main programs in [app/](app) (compiled to `main.x` by default)
- Tests in [tests/](tests/) (compiled to `unit_tests.x` by default).

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
# make and change to build directory
$ mkdir build && cd build

# configure and generate Makefile of project
$ cmake .. # argument is location of CMakelists.txt

# to run cmake gui and view variable values
$ ccmake ..

# To compile project
$ make

# To build project, unit tests and also run unit tests
$ make gtest

# To run project
$ ./main.x

# To run unit tests
$ ./unit_tests.x
```
## C++ Naming Conventions

| Construct                  | Naming Rule        |
|:--------------------------:|:------------------:|
| namespace                  | lowerCamelCase     |
| function name              | lowerCamelCase     |
| variables, function params | lowerCamelCase     |
| struct data member         | lowerCamelCase     |
|                            |                    |
| class name (and file name) | UpperCamelCase     |
| enum name                  | UpperCamelCase     |
| typedef, aliases           | UpperCamelCase     |
| struct name                | UpperCamelCase     |
| template typename          | UpperCamelCase     |
|                            |                    |
| private class field        | m_lowerCamelCase   |
|                            |                    |
| constants                  | UPPER_SNAKE_CASE   |
| enum variables             | UPPER_SNAKE_CASE   |
| macro variables            | UPPER_SNAKE_CASE   |
|                            |                    |
| global variable            | g_lowerCamelCase   |
| static variable            | s_lowerCamelCase   |

## Git Commit Style

**feat**: a new feature <br/>
**fix**: a bug fix <br/>
**docs**: changes to documentation <br/>
**style**: formatting, style corrections, no code change <br/>
**refactor**: refactoring production code <br/>
**test**: adding tests, refactoring test; no production code change <br/>
**chore**: updating build tasks, no production code change <br/>
