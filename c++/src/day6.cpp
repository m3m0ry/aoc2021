#include "day6.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>

#include <range/v3/all.hpp>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;
namespace rv = ranges::views;
namespace r = ranges;

void Day6::parse(std::vector<std::string> input) {
    sr::transform(strutil::split(input[0], ","), std::back_inserter(numbers), strutil::parse_string<int>);
}

std::string Day6::part1() const {
    //naive implementation
    auto fishes = numbers;
    for(auto n: srv::iota(0, 80)) {
        sr::for_each(fishes, [](auto& i){--i;});
        auto new_fish = sr::count(fishes, -1);
        sr::for_each(fishes, [](auto& i){i=i<0?6:i;});
        sr::for_each(srv::iota(0,new_fish), [&fishes](auto _){fishes.push_back(8);});
    }
    return strutil::to_string(fishes.size());
}

std::string Day6::part2() const {
    //map implementation
    std::map<int,long long> fishes;
    sr::for_each(srv::iota(-1,9),[&fishes, this](auto i){fishes[i] = sr::count(this->numbers, i);});
    for(auto n: srv::iota(0,256)){
        std::map<int,long long> next_fishes;
        sr::for_each(srv::iota(0,9), [&next_fishes, &fishes](auto i){next_fishes[i-1] = fishes[i];});
        next_fishes[8] = next_fishes[-1];
        next_fishes[6] += next_fishes[-1];
        next_fishes[-1] = 0;
        fishes = std::move(next_fishes);
    }
    auto sum_fishes = r::accumulate(fishes | rv::transform([](auto i){return i.second;}), static_cast<long long>(0));
    return strutil::to_string(sum_fishes);
}
