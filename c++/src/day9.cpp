#include "day9.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <map>
#include <stdexcept>

#include <range/v3/all.hpp>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;
namespace rv = ranges::views;
namespace ra = ranges::actions;
namespace r = ranges;



using coord = std::pair<int,int>;

void Day9::parse(std::vector<std::string> input) {
    numbers = Eigen::ArrayXXi(input.size()+2, input[0].size()+2);
    numbers.fill(10);
    for(auto [i,line]: rv::enumerate(input)){
        for(auto [j,n]: rv::enumerate(line)){
            numbers(i+1,j+1) = strutil::parse_string<int>(strutil::to_string(n));
        }
    }
}


bool is_lowest(const Eigen::ArrayXXi& a, int i, int j){
    for(auto k: {-1, 1}){
        if(a(i,j) >= a(i+k, j) || a(i,j) >= a(i,j+k))
            return false;
    }
    return true;
}

std::string Day9::part1() const {
    std::vector<int> lowests;
    for(auto i: srv::iota(1, numbers.rows()-1)){
        for(auto j: srv::iota(1, numbers.cols()-1)){
            if(is_lowest(numbers, i, j)) {
                lowests.push_back(numbers(i,j));
            }
        }
    }
    auto result = r::accumulate(lowests, 0) + lowests.size();
    return strutil::to_string(result);
}




coord lowest_neighbor(const Eigen::ArrayXXi& a, coord current){
    auto [i,j] = current;
    for(auto k: {-1, 1}) {
        if (a(i,j) > a(i+k,j)){
            return {i+k, j};
        }
        else if(a(i,j) > a(i,j+k)){
            return {i, j+k};
        }
    }
    throw std::runtime_error("WTF");
}

coord kullern(const Eigen::ArrayXXi& a, coord start, const std::map<coord, int> lowests){
    auto [i,j] = start;

    while(!lowests.contains({i,j})){
        auto new_start = lowest_neighbor(a, {i,j});
        i = new_start.first;
        j = new_start.second;
    }
    return {i,j};
}

std::string Day9::part2() const {
    std::map<coord, int> lowests;
    for(auto i: srv::iota(1, numbers.rows()-1)){
        for(auto j: srv::iota(1, numbers.cols()-1)){
            if(is_lowest(numbers, i, j)) {
                lowests[{i,j}] = 0;
            }
        }
    }

    for(auto i: srv::iota(1, numbers.rows()-1)){
        for(auto j: srv::iota(1, numbers.cols()-1)){
            if(numbers(i,j) < 9){
                ++lowests[kullern(numbers, {i, j}, lowests)];
            }
        }
    }

    auto basin_sizes = lowests
        | rv::transform([](auto v){return v.second;})
        | r::to<std::vector>();
    r::sort(basin_sizes);
    auto result = r::accumulate(basin_sizes | rv::take_last(3), 1, r::multiplies{});
    return strutil::to_string(result);
}
