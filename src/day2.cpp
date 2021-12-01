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

void Day2::parse(std::vector<std::string> input) {
    auto view = input | rv::transform(strutil::parse_string<int>);
    ranges::copy(view, std::back_inserter(numbers));
}

std::string Day2::part1() const {
    return "Not Implemented!!!";
}

std::string Day2::part2() const {
    return "Not Implemented!!!";
}
