#include "day4.hpp"

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

void Day4::parse(std::vector<std::string> input) {
    sr::transform(strutil::split(input[0], ","), std::back_inserter(numbers), strutil::parse_string<int>);
    auto bingo_chunks = input | rv::drop(1) | rv::filter([](auto s){return !s.empty();}) | rv::chunk(5);
    for(auto bingo_chunk: bingo_chunks){
        bingo_table bingo;
        for(auto [i, line] : rv::enumerate(bingo_chunk)){
            auto v = strutil::split(line | r::to<std::string>(), " ");
            auto five_numbers = v
                | rv::filter([](auto s){return !s.empty();}) 
                | rv::transform([](std::string s){return strutil::parse_string<int>(s);});
            for(auto [j, n]: rv::enumerate(five_numbers)){
                bingo[i][j] = n;
            }
        }
        bingos.push_back(bingo);
    }
}

std::string Day4::part1() const {
    return "Not Implemented!!!";
}

std::string Day4::part2() const {
    return "Not Implemented!!!";
}
