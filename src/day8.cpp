#include "day8.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>

#include <range/v3/all.hpp>

#include "utils.hpp"
#include "strutil.hpp"

namespace srv = std::ranges::views;
namespace sr = std::ranges;
namespace rv = ranges::views;
namespace r = ranges;

void Day8::parse(std::vector<std::string> input) {
    for(auto line: input){
        auto v = strutil::split(line, " | ");
        auto signal_patterns = strutil::split(v[0], " ");
        numbers.push_back(std::move(signal_patterns));
        auto output_patterns = strutil::split(v[1], " ");
        outputs.push_back(std::move(output_patterns));
    }
    //sr::for_each(numbers, [](auto s){sr::for_each(s, show<std::string>);});
}

std::string Day8::part1() const {
    auto result = r::count_if(rv::join(outputs), [](auto s){auto n = s.size(); return n <= 4 || n == 7;});
    return strutil::to_string(result);
}

std::string Day8::part2() const {
    const std::vector<char> init = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    const std::vector<char> one = {'c', 'f'};
    const std::vector<char> seven = {'a', 'c', 'f'};
    const std::vector<char> four = {'b', 'c', 'd', 'f'};
    for(auto i: srv::iota(0u, numbers.size())){
        std::map<char, std::vector<char>> mapping;
        mapping['a'] = init;
        mapping['b'] = init;
        mapping['c'] = init;
        mapping['d'] = init;
        mapping['e'] = init;
        mapping['f'] = init;
        mapping['g'] = init;
        auto number = numbers[i];
        auto output = outputs[i];
        for(auto n: number){
            if(n.size() == 2){
                std::vector<char> new_set;
                sr::set_intersection(mapping[n[0]], one, std::inserter(new_set, new_set.begin()));
                mapping[n[0]] = new_set;
                new_set.clear();
                sr::set_intersection(mapping[n[1]], one, std::inserter(new_set, new_set.begin()));
                mapping[n[1]] = new_set;
            }
            else if(n.size() == 3){
                std::vector<char> new_set;
                sr::set_intersection(mapping[n[0]], seven, std::inserter(new_set, new_set.begin()));
                mapping[n[0]] = new_set;
                new_set.clear();
                sr::set_intersection(mapping[n[1]], seven, std::inserter(new_set, new_set.begin()));
                mapping[n[1]] = new_set;
                new_set.clear();
                sr::for_each(mapping[n[2]], show<char>);
                sr::set_intersection(mapping[n[2]], seven, std::inserter(new_set, new_set.begin()));
                sr::for_each(mapping[n[2]], show<char>);
                mapping[n[2]] = new_set;
            }
            else if(n.size() == 4){
                std::vector<char> new_set;
                sr::set_intersection(mapping[n[0]], four, std::inserter(new_set, new_set.begin()));
                mapping[n[0]] = new_set;
                new_set.clear();
                sr::set_intersection(mapping[n[1]], four, std::inserter(new_set, new_set.begin()));
                mapping[n[1]] = new_set;
                new_set.clear();
                sr::set_intersection(mapping[n[2]], four, std::inserter(new_set, new_set.begin()));
                mapping[n[2]] = new_set;
                new_set.clear();
                sr::set_intersection(mapping[n[3]], four, std::inserter(new_set, new_set.begin()));
                mapping[n[3]] = new_set;
            }
        }
        for(auto [k,v]: mapping){
            std::cout << k << ": ";
            for(const auto& i: v){
                std::cout << i << ", ";
            }
            std::cout << std::endl;
        }
            std::cout << std::endl;
    }
    return "Not Implemented!!!";
}
