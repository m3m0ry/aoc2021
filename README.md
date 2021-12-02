# aoc2021
Solutions of Advent of Code 2021 in C++.

## Dependencies
- g++-11
- cmake
- ninja
- inotify-tools
- sh

## Build
Use `mkdir build` `cd build` `cmake .. -G Ninja` `cmake --build .` to compile the solution.
The solution will be under `build/apps/aoc2021`

## Usage
Execute `aoc2021` for usage.

## Scripts
- `workwork.sh` will compile the project, everytime there was a change in `src`, `include` or `inputs` folder.
- `newday.sh` creates files for a new day. It is necessary to implement a new `case` in `src/boiler.cpp`.

## TODO
- add warnings from `GCC.mk` into `CMakeLists.txt`
- use `clang-format`
- use `clang-tidy`
- use `cppcheck`
- use GitHub's CI?
