# aoc2021
Solutions of Advent of Code 2021 in C++.

## Dependencies
- g++-11
- make
- inotify-tools
- sh

## Build
Use `make` to compile the solutions.
Use `make TAG=<compiler>` to specify the configuration which is in a `<compiler>.mk` file.

## Usage
Execute `./aoc2021-<compiler>` for usage.

## Scripts
- `workwork.sh` will compile the project, everytime there was a change in `src`, `include` or `inputs` folder.
- `newday.sh` creates files for a new day. It is necessary to implement a new `case` in `src/boiler.cpp`.

