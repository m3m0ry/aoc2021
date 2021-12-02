#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Day2{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    std::vector<std::pair<std::string, int>> movement;
};
