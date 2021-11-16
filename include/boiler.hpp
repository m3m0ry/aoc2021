#include <iostream>
#include <filesystem>
#include <string>

#include "concepts.hpp"
#include "day.hpp"


template<Day T>
void do_day(T day){
    namespace fs = std::filesystem;
    fs::path input_folder = "./inputs";
    std::string test = "test";
    std::string_view input(test.begin(), test.end());
    day.parse(input);
    std::cout << day.part1() << std::endl;
    std::cout << day.part2() << std::endl;
}


void run_day(int day);
