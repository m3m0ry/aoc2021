#include "day10.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <set>
#include <exception>

#include <range/v3/all.hpp>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;
namespace rv = ranges::views;
namespace r = ranges;

void Day10::parse(std::vector<std::string> input) {
    lines = input;
}


int corruption(const std::string& line){
    std::stack<char> stack;
    std::map<char, int> cost = {{')',3},{']',57},{'}',1197},{'>',25137}};
    std::map<char, char> closing = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
    for(auto c: line){
        if (std::set<char>{'(', '<', '{', '['}.contains(c))
            stack.push(c);
        else if(closing[stack.top()] != c)
            return cost[c];
        else
            stack.pop();
    }
    return 0;
}

long missing(const std::string& line){
    std::stack<char> stack;
    std::map<char, long> cost = {{'(',1},{'[',2},{'{',3},{'<',4}};
    std::map<char, char> closing = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
    for(auto c: line){
        if (std::set<char>{'(', '<', '{', '['}.contains(c))
            stack.push(c);
        else if(closing[stack.top()] != c)
            return 0;
        else
            stack.pop();
    }
    long result = 0;
    while(!stack.empty()){
        result *= 5;
        result += cost[stack.top()];
        stack.pop();
    }
    return result;
}

std::string Day10::part1() const {
    auto result = r::accumulate(lines | rv::transform(corruption), 0);
    return strutil::to_string(result);
}

std::string Day10::part2() const {
    auto incomplete = lines
        | rv::transform(missing)
        | rv::filter([](auto i){return i != 0;})
        | r::to<std::vector<long>>;
    r::sort(incomplete);
    auto result = incomplete[incomplete.size()/2];
    return strutil::to_string(result);
}
