#include <iostream>
#include <filesystem>
#include <string>
#include <string_view>

#include "concepts.hpp"
#include "day.hpp"


template<Day T>
void do_day(T day, std::string_view input){
    day.parse(input);
    std::cout << day.part1() << std::endl;
    std::cout << day.part2() << std::endl;
}

void run_day(int day);
