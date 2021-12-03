#include "day0.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

#include <range/v3/all.hpp>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;
namespace rv = ranges::views;
namespace r = ranges;

void Day0::parse(std::vector<std::string> input) {
    auto view = input | rv::transform(strutil::parse_string<int>);
    sr::copy(view, std::back_inserter(numbers));
}

std::string Day0::part1() const {
    return "Not Implemented!!!";
}

std::string Day0::part2() const {
    return "Not Implemented!!!";
}
