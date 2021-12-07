#include "day7.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstdlib>

#include <range/v3/all.hpp>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;
namespace rv = ranges::views;
namespace r = ranges;

void Day7::parse(std::vector<std::string> input) {
    sr::transform(strutil::split(input[0], ","), std::back_inserter(numbers), strutil::parse_string<int>);
}


int fuel(const std::vector<int> numbers, int position){
    auto fuels = numbers | rv::transform([position](auto i){return abs(i-position);});
    return r::accumulate(fuels, 0);
}

int fuel2(const std::vector<int> numbers, int position){
    auto fuels = numbers | rv::transform([position](auto i){auto n = abs(i-position); return (n*(n+1))/2;});
    return r::accumulate(fuels, 0);
}

std::string Day7::part1() const {
    auto average = fuel(numbers, 2);
    auto fuels = srv::iota(sr::min(numbers), sr::max(numbers)) 
        | srv::transform([this](auto i){return fuel(numbers, i);});
    return strutil::to_string(sr::min(fuels));
}

std::string Day7::part2() const {
    auto average = fuel(numbers, 2);
    auto fuels = srv::iota(sr::min(numbers), sr::max(numbers)) 
        | srv::transform([this](auto i){return fuel2(numbers, i);});
    return strutil::to_string(sr::min(fuels));
}
