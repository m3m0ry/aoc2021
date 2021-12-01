#include "day1.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

#include "utils.hpp"
#include "strutil.hpp"

namespace rv = std::ranges::views;
namespace ranges = std::ranges;

void Day1::parse(std::vector<std::string> input) {
    auto view = input | rv::transform(strutil::parse_string<int>);
    ranges::copy(view, std::back_inserter(numbers));
}

std::string Day1::part1() const {
    // zip_view is available in C++23 :(
    // how do I do this with views?
    //std::vector<int> changes;
    //ranges::transform(numbers, rv::drop(numbers,1), std::back_inserter(changes), [](auto i, auto j){return j - i > 0;});
    //auto result = std::accumulate(changes.begin(), changes.end(), 0);

    int result = 0;
    for(auto i: rv::iota(1u, numbers.size())) {
        result += numbers[i] - numbers[i-1] > 0;
    }

    return strutil::to_string(result);
}

std::string Day1::part2() const {
    // zip_view is available in C++23 :(
    // how do I do this with views?
    //auto last = numbers[1];
    //auto lastlast = numbers[0];
    //std::vector<int> accs;
    //for(auto i: numbers | rv::drop(2)) {
    //    accs.push_back(i + last + lastlast);
    //    lastlast = last;
    //    last = i;
    //}
    //std::vector<int> changes;
    //ranges::transform(accs, rv::drop(accs,1), std::back_inserter(changes), [](auto i, auto j){return j - i > 0;});
    //auto result = std::accumulate(changes.begin(), changes.end(), 0);

    int result = 0;
    for(auto i: rv::iota(3u, numbers.size())) {
        auto first = numbers[i-1] + numbers[i-2] + numbers[i-3];
        auto second = numbers[i] + numbers[i-1] + numbers[i-2];
        result += second - first > 0;
    }
    return strutil::to_string(result);
}
