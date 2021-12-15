#include "day11.hpp"

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

void Day11::parse(std::vector<std::string> input) {
    numbers = cave::Zero(input.size()+2, input[0].size()+2);
    for(auto [i,line]: rv::enumerate(input)){
        for(auto [j,n]: rv::enumerate(line)){
            numbers(i+1,j+1) = strutil::parse_string<int>(strutil::to_string(n));
        }
    }
    std::cout << numbers << std::endl << std::endl;;
}

void step(const cave& src, cave& dst){
    for(auto i: srv::iota(1, src.rows()-1)){
        for(auto j: srv::iota(1, src.cols()-1)){
            if(src(i,j) == 0){
                dst(i,j) = 0;
            }
            else if(src(i,j) > 9){
                dst(i,j) = 0;
            }
            else {
                int sum = 0;
                for(auto k: srv::iota(-1, 2)){
                    for(auto l: srv::iota(-1, 2)){
                        sum += src(i+k, j+l) > 9 ? 1 : 0;
                    }
                }
                dst(i,j) = src(i,j) + sum;
            }
        }
    }
}


int flashes(cave& energy) {
    energy(Eigen::seq(1, Eigen::last-1), Eigen::seq(1, Eigen::last-1)) += 1;
    auto dst = energy;
    do{
        step(energy, dst);
        std::swap(energy, dst);
    } while(!(energy == dst).all());
    const auto & inner = energy(Eigen::seq(1, Eigen::last-1), Eigen::seq(1, Eigen::last-1));
    return inner.size() - inner.count();

}

std::string Day11::part1() const {
    cave energy = numbers;
    int result = 0;
    for(auto i: srv::iota(0, 100)){
        auto f = flashes(energy);
        result += f;
    }
    return strutil::to_string(result);
}

std::string Day11::part2() const {
    cave energy = numbers;
    for(auto i: srv::iota(1)){
        flashes(energy);
        if((energy == 0).all())
            return strutil::to_string(i);
    }
    return "Unreachable";
}
