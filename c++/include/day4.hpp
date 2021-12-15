#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <array>

#include <Eigen/Dense>

using bingo_table = Eigen::Array<int, 5,5>;
using bingo_table_bool = Eigen::Array<bool, 5,5>;

struct Day4{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    std::vector<int> numbers;
    std::vector<bingo_table> bingos;
};
