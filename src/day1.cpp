#include "day1.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <thread>

#include "utils.hpp"
#include "strutil.hpp"

namespace rv = std::ranges::views;
namespace ranges = std::ranges;

void Day1::parse(std::vector<std::string> input) {
    auto view = input | rv::transform(strutil::parse_string<int>);
    ranges::copy(view, std::back_inserter(numbers));
}

std::string Day1::part1() const {
    auto filtered = numbers
        | rv::filter([&](auto i)
                {return ranges::any_of(numbers, [&i](auto j)
                        {return i+j == 2020;});})
        | rv::take(2)
        | rv::common;
    auto result = std::accumulate(filtered.begin(), filtered.end(), 1, std::multiplies<int>());
    return strutil::to_string(result);
}

std::string Day1::part2() const {
    //ranges::for_each(numbers, show);
    return "";
}
