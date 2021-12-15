#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Day1{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    std::vector<int> numbers;
};
