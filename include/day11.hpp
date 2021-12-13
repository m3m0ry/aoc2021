#pragma once
#include <vector>
#include <string>
#include <iostream>

#include <Eigen/Dense>
using cave = Eigen::ArrayXXi;

struct Day11{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    cave numbers;
};
