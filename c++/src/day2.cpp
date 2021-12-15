#include "day2.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;

static std::unordered_map<std::string,std::function<void(int&, int&, int)>> const table_part1 = {
    {"forward", [](int& horizontal, int& depth, int value){ horizontal += value;}},
    {"down", [](int& horizontal, int& depth, int value){ depth += value;}},
    {"up", [](int& horizontal, int& depth, int value){ depth -= value;}}};

static std::unordered_map<std::string,std::function<void(int&, int&, int&, int)>> const table_part2 = {
    {"forward", [](int& horizontal, int& depth, int& aim, int value){ horizontal += value; depth += aim * value;}},
    {"down", [](int& horizontal, int& depth, int& aim, int value){ aim += value;}},
    {"up", [](int& horizontal, int& depth, int& aim, int value){ aim -= value;}}};

void Day2::parse(std::vector<std::string> input) {
    auto view = input | srv::transform([](auto l)
            {auto vec = strutil::split(l, " ");
             return std::make_pair(vec[0], strutil::parse_string<int>(vec[1]));});
    sr::copy(view, std::back_inserter(movement));
}

std::string Day2::part1() const {
    int horizontal = 0;
    int depth = 0;
    auto sc = [&horizontal, &depth](auto p){
        table_part1.at(p.first)(horizontal, depth, p.second);
    };
    sr::for_each(movement, sc);
    return strutil::to_string(horizontal * depth);
}

std::string Day2::part2() const {
    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    auto sc = [&horizontal, &depth, &aim](auto p){
        table_part2.at(p.first)(horizontal, depth, aim, p.second);
    };
    sr::for_each(movement, sc);
    return strutil::to_string(horizontal * depth);
}
