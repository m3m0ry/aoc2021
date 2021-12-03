#include "day3.hpp"

#include <ranges>
#include <iostream>
#include <cmath>
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

int toInt(const std::string &s)
{
    int n = 0;

    for (int i = 0; i < s.size(); i++) {
        n <<= 1;
        n |= s[i] - '0';
    }

    return n;
}

void Day3::parse(std::vector<std::string> input) {
    sr::copy(input, std::back_inserter(numbers));
    number_length = input[0].size();
}

std::string Day3::part1() const {
    auto gamma = 0;
    for(auto i: srv::iota(0u, number_length)) {
        if (r::count_if(numbers, [i](auto s){return s[i]=='1';}) > numbers.size()/2){
            gamma |= 1 << number_length - i - 1;
        }
    }
    auto epsilon = gamma ^ ((1 << number_length)-1);
    return strutil::to_string(gamma*epsilon);;
}

std::string Day3::part2() const {
    auto oxygen = numbers;
    auto co2 = numbers;
    for(auto i: srv::iota(0u, number_length)) {
        auto one = sr::count_if(oxygen, [i](auto s){return s[i]=='1';}) * 2 >= oxygen.size();
        std::erase_if(oxygen, [i, one](auto s){return one?s[i]=='0':s[i]=='1';});
        if(oxygen.size() == 1)
            break;
    }
    for(auto i: srv::iota(0u, number_length)) {
        auto one = sr::count_if(co2, [i](auto s){return s[i]=='1';}) * 2 < co2.size();
        std::erase_if(co2, [i, one](auto s){return one?s[i]=='0':s[i]=='1';});
        if(co2.size() == 1)
            break;
    }
    return strutil::to_string(toInt(oxygen[0]) * toInt(co2[0]));
}
