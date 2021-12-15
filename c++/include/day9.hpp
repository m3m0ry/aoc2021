#pragma once
#include <vector>
#include <string>
#include <iostream>

#include <Eigen/Dense>
using heights_array = Eigen::ArrayXXi;

struct Day9{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    heights_array numbers;
};
