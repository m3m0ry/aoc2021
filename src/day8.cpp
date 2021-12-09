#include "day8.hpp"

#include <ranges>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <exception>
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

template<typename T>
std::set<T> intersection(const std::set<T>& a, const std::set<T>& b){
    std::set<T> new_set;
    sr::set_intersection(a, b, std::inserter(new_set, new_set.begin()));
    return new_set;
}


template<typename T>
std::set<T> difference(const std::set<T>& a, const std::set<T>& b){
    std::set<T> new_set;
    sr::set_difference(a, b, std::inserter(new_set, new_set.begin()));
    return new_set;
}

std::string Day8::part2() const {
    int result = 0;
    const std::set<char> init = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    const std::set<char> zero = {'a', 'b', 'c', 'e', 'f', 'g'};
    const std::set<char> one = {'c', 'f'};
    const std::set<char> two = {'a', 'c', 'd', 'e', 'g'};
    const std::set<char> three = {'a', 'c', 'd', 'f', 'g'};
    const std::set<char> four = {'b', 'c', 'd', 'f'};
    const std::set<char> five = {'a', 'b', 'd', 'f', 'g'};
    const std::set<char> six = {'a', 'b', 'd', 'e', 'f', 'g',};
    const std::set<char> seven = {'a', 'c', 'f'};
    const std::set<char> eight = init;
    const std::set<char> nine = {'a', 'b', 'c', 'd', 'f', 'g'};
    const std::set<char> zero_six_nine = intersection(intersection(zero, six), nine);
    const std::set<char> two_three_five = intersection(intersection(two, three), five);
    std::map<std::set<char>, int> set_to_number = {{zero,0},{one,1},{two,2},{three,3},{four,4},{five,5},{six,6},{seven,7},{eight,8},{nine,9}};
    for(auto i: srv::iota(0u, numbers.size())){
        std::map<char, std::set<char>> mapping = {{'a',init},{'b',init},{'c',init},{'d',init},{'e',init},{'f',init},{'g',init}};
        auto number = numbers[i];
        auto output = outputs[i];
        for(auto n: number){
            std::set<char> set_number;
            if(n.size() <= 6){
                if(n.size() == 2)
                    set_number = one;
                else if(n.size() == 3)
                    set_number = seven;
                else if(n.size() == 4)
                    set_number = four;
                else if(n.size() == 5)
                    set_number = two_three_five;
                else if(n.size() == 6)
                    set_number = zero_six_nine;
                if(n.size() <= 4){
                    for(auto c: n){
                        mapping[c] = intersection(mapping[c], set_number);
                    }
                }
                for(auto c: difference(init, std::set<char>{n.begin(), n.end()})){
                    mapping[c] = difference(mapping[c], set_number);
                }
            }
        }
        //apply uniques on others
        for(auto [k,v]: mapping){
            for(auto [l,w]: mapping){
                if (k != l && v.size() == 1){
                    mapping[l] = difference(w, v);
                }
            }
        }
        //create final mapping
        std::map<char, char> final_mapping;
        for(auto [k,v]: mapping){
            if(v.size() != 1)
                throw std::runtime_error("WTF");
            final_mapping[k] = *v.begin();
        }
        //sum current number on result
        int num = 0;
        for(auto [j,o]: output | rv::reverse | rv::enumerate){
            auto mapped = rv::transform(o, [&final_mapping](auto c){return final_mapping[c];}) | r::to<std::set<char>>;
            num += set_to_number[mapped] * static_cast<int>(std::pow(10,j));
        }

        result += num;
    }
    return strutil::to_string(result);
}
