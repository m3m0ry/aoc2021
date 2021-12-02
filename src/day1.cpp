#include "day1.hpp"

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

void Day1::parse(std::vector<std::string> input) {
    auto view = input | srv::transform(strutil::parse_string<int>);
    sr::copy(view, std::back_inserter(numbers));
}

std::string Day1::part1() const {
    auto view = rv::zip_with(std::less{}, numbers, rv::drop(numbers,1));
    int result = r::accumulate(view, 0);
    return strutil::to_string(result);
}

std::string Day1::part2() const {
    auto view = rv::zip_with(std::less{}, numbers, rv::drop(numbers,3));
    int result = r::accumulate(view, 0);
    return strutil::to_string(result);
}
