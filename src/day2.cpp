#include "day2.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

#include "utils.hpp"
#include "strutil.hpp"

namespace rv = std::ranges::views;
namespace ranges = std::ranges;

using namespace std::placeholders;

void Day2::parse(std::vector<std::string> input) {
    auto view = input | rv::transform([](auto l)
            {auto vec = strutil::split(l, " ");
             return std::make_pair(table.at(vec[0]), strutil::parse_string<int>(vec[1]));});
    ranges::copy(view, std::back_inserter(movement));
}

std::string Day2::part1() const {
    int horizontal = 0;
    int depth = 0;
    auto sc = [&horizontal, &depth](auto p){
        switch(p.first) {
            case dir::forward:
                horizontal += p.second;
                break;
            case dir::up:
                depth -= p.second;
                break;
            case dir::down:
                depth += p.second;
                break;
        }
    };
    ranges::for_each(movement, sc);
    return strutil::to_string(horizontal * depth);
}

std::string Day2::part2() const {
    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    auto sc = [&horizontal, &depth, &aim](auto p){
        switch(p.first) {
            case dir::forward:
                horizontal += p.second;
                depth += aim * p.second;
                break;
            case dir::up:
                aim -= p.second;
                break;
            case dir::down:
                aim += p.second;
                break;
        }
    };
    ranges::for_each(movement, sc);
    return strutil::to_string(horizontal * depth);
}
