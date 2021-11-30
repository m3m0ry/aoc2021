#!/bin/bash
if [ $# != 2 ]; then
    echo "usage: sh workwork.sh <day> <tag>"
    echo "       day: 1-25 of Advent of Code Days"
    echo "       tag: GCC, GCCdebug or Clang"
    exit
fi

while inotifywait -e modify -q -r src include inputs; do
    clear
    make TAG=$2
    if [ $? -eq 0 ]; then
        ./aoc2021-$2 $1 ./inputs/day$1.txt
    fi
done
