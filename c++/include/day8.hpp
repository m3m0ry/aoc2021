#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Day8{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    std::vector<std::vector<std::string>> numbers;
    std::vector<std::vector<std::string>> outputs;
};
