#include "day5.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <array>
#include <concepts>

#include <range/v3/all.hpp>
#include <Eigen/Dense>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;
namespace rv = ranges::views;
namespace r = ranges;

using Eigen::ArrayXXi;
using Eigen::seq;

void Day5::parse(std::vector<std::string> input) {
    auto view = input | rv::transform(strutil::parse_string<int>);
    for(auto s: input) { // TODO better, simpler parsing
        auto v = strutil::split(s, " -> ");
        auto start = v[0];
        auto v1 = strutil::split(start, ",");
        auto x1 = strutil::parse_string<int>(v1[0]);
        auto y1 = strutil::parse_string<int>(v1[1]);
        auto end = v[1];
        auto v2 = strutil::split(end, ",");
        auto x2 = strutil::parse_string<int>(v2[0]);
        auto y2 = strutil::parse_string<int>(v2[1]);
        numbers.push_back({twod{x1, x2},twod{y1, y2}});
    }

    auto max_xs = numbers | srv::transform([](auto c){return c.first.first > c.first.second ? c.first.first : c.first.second;});
    max_x = sr::max(max_xs);
    auto max_ys = numbers | srv::transform([](auto c){return c.second.first > c.second.second ? c.second.first : c.second.second;});
    max_y = sr::max(max_ys);
}

std::string Day5::part1() const {
    ArrayXXi m = {max_x+1, max_y+1};
    m.fill(0);

    for(auto [x,y]: numbers){
        auto [x1, x2] = x;
        auto [y1, y2] = y;
        if(x1 == x2){
            if(y1 > y2)
                std::swap(y1, y2);
            m(x1, seq(y1, y2)) += 1;
        }
        else if(y1 == y2){
            if(x1 > x2)
                std::swap(x1, x2);
            m(seq(x1,x2), y1) += 1;
        }
    }
    auto result = (m > 1).count();
    return strutil::to_string(result);
}


template<std::integral T>
std::vector<T> step_inclusive_iota(T start, T end, T step) {
    std::vector<T> result;
    T current = start;
    while(current != end) {
        result.push_back(current);
        current += step;
    }
    result.push_back(current);
    return result;
}

std::string Day5::part2() const {
    ArrayXXi m = {max_x+1, max_y+1};
    m.fill(0);

    for(auto [x,y]: numbers){
        auto [x1, x2] = x;
        auto [y1, y2] = y;
        //horizontal
        if(x1 == x2){
            if(y1 > y2)
                std::swap(y1, y2);
            m(x1, seq(y1, y2)) += 1;
        }
        //vertical
        else if(y1 == y2){
            if(x1 > x2)
                std::swap(x1, x2);
            m(seq(x1,x2), y1) += 1;
        }
        //diagonal
        else{
            auto xs = step_inclusive_iota(x1, x2, x1<x2?1:-1);
            auto ys = step_inclusive_iota(y1, y2, y1<y2?1:-1);
            for(auto [i,j]: rv::zip(xs, ys)){
                m(i,j) += 1;
            }
        }
    }
    auto result = (m > 1).count();
    return strutil::to_string(result);
}
