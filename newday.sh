#!/bin/sh
if [ $# != 2 1; then
    echo "usage: sh newday.sh <day>"
    echo "       day: 1-25 of Advent of Code Days"
    exit
fi

cp src/day0.cpp src/day$1.cpp
sed -i "s/0/$1/g" src/day$1.cpp

cp include/day0.hpp include/day$1.hpp
sed -i "s/0/$1/g" include/day$1.hpp

touch inputs/day$1.txt

echo "#include \"day$1.hpp\"" >> include/day.hpp
echo "TODO: add new case in src/boler.cpp"
