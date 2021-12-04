#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <array>

using bingo_table = std::array<std::array<int,5>,5>;

struct Day4{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    std::vector<int> numbers;
    std::vector<bingo_table> bingos;
};
