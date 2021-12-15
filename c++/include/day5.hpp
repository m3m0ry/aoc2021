#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <utility>

using twod = std::pair<int,int>;
using coords = std::pair<twod, twod>;

struct Day5{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    std::vector<coords> numbers;
    int max_x;
    int max_y;
};
