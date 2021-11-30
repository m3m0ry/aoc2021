#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <chrono>

#include "concepts.hpp"
#include "utils.hpp"
#include "day.hpp"


template<Day T>
void do_day(std::vector<std::string> input){
    using std::chrono::steady_clock;

    T day = T();
    day.parse(input);

    auto part1_start = steady_clock::now();
    auto part1 = day.part1();
    std::cout << "Part 1\t" << part1 << "\t Took\t" << since(part1_start).count() << "ms" << std::endl;

    auto part2_start = steady_clock::now();
    auto part2 = day.part2();
    std::cout << "Part 2\t" << part2 << "\t Took\t" << since(part2_start).count() << "ms" << std::endl;
}

void run_day(int day, const std::string& input_file);

