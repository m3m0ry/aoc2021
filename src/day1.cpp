#include "day1.hpp"

#include <vector>
#include <ranges>
#include <iostream>

namespace views = std::ranges::views;

void Day1::parse(std::string_view input) {
    auto split = input | views::split('\n') | views::transform([](auto&& str) { return std::string_view(&*str.begin(), std::ranges::distance(str)); });
    for (auto&& line : split){
        std::cout << line << std::endl;
    }
}

std::string Day1::part1() const {
    return {"part1_return"};
}

std::string Day1::part2() const {
    return {"part2_return"};
}
