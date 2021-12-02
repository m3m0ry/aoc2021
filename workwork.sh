#!/bin/sh
if [ $# != 1 ]; then
    echo "usage: sh workwork.sh <day>"
    echo "       day: 1-25 of Advent of Code Days"
    exit
fi

rm -rf build
mkdir build
cd build
cmake .. -G Ninja

while
    clear
    cmake --build . -j 4
    if [ $? -eq 0 ]; then
        ./apps/aoc2021 $1 ../inputs/day$1.txt
    fi
    inotifywait -e modify -q -r ../src ../include ../inputs
do true; done
