#!/bin/bash
if [ $# != 1 ]; then
    echo "usage: sh workwork.sh <day>"
    echo "       day: 1-25 of Advent of Code Days"
    exit
fi

while inotifywait -e modify -q -r src include inputs; do
    clear
    make
    if [ $? -eq 0 ]; then
        ./aoc2021-GCC $1 ./inputs/day$1.txt
    fi
done
