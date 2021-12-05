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

using Eigen::seq;

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
                bingo(i,j) = n;
            }
        }
        bingos.push_back(std::move(bingo));
    }
}


int sum_unmarked(const bingo_table& bingo, const bingo_table_bool& played) {
    int result = 0;
    for(auto i: srv::iota(0,5)){
        for(auto j: srv::iota(0,5)){
            if (!played(i,j))
                result += bingo(i,j);
        }
    }
    return result;
}

void mark_number(const bingo_table& bingo, bingo_table_bool& played, int number) {
    for(auto i: srv::iota(0,5)){
        for(auto j: srv::iota(0,5)){
            if (bingo(i,j) == number)
                played(i,j) = true;
        }
    }
}

bool check_winner(const bingo_table_bool& played) {
    for(auto r: srv::iota(0,5)){
        if(played(Eigen::all, r).count() == 5 || played(r, Eigen::all).count() == 5){
            return true;
        }
    }
    return false;
}


std::string Day4::part1() const {
    bingo_table_bool bools;
    bools.fill(false);
    std::vector<bingo_table_bool> played_bingos;
    sr::for_each(srv::iota(0u, bingos.size()), [&played_bingos, &bools](auto _){played_bingos.push_back(bools);});


    for(auto n: numbers){
        //play number
        for(auto c: srv::iota(0u, bingos.size())){
            auto& bingo = bingos[c];
            auto& played = played_bingos[c];
            mark_number(bingo, played, n);
            if(check_winner(played)){
                return strutil::to_string(sum_unmarked(bingo, played)*n);
            }
        }
    }
    return "No Winner!!!";
}



std::string Day4::part2() const {
    bingo_table_bool bools;
    bools.fill(false);
    std::vector<bingo_table_bool> played_bingos;
    sr::for_each(srv::iota(0u, bingos.size()), [&played_bingos, &bools](auto _){played_bingos.push_back(bools);});
    auto bingos = this->bingos;

    for(auto n: numbers){
        auto playing = bingos.size();
        for(auto c: srv::iota(0u, bingos.size())){
            auto& bingo = bingos[c];
            auto& played = played_bingos[c];
            mark_number(bingo, played, n);
            //TODO why is all_of so fast and 
            //if(sr::count_if(played_bingos, check_winner) == played_bingos.size()){ //3 seconds vs 82ms
            // so slow???
            if(sr::all_of(played_bingos, check_winner)){
                return strutil::to_string(sum_unmarked(bingo, played)*n);
            }
        }
    }
    return "No Last Loser!!!";
}
