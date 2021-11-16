#include "boiler.hpp"

#include <fstream>
#include <iterator>

namespace fs = std::filesystem;

void run_day(int day)
{
    namespace fs = std::filesystem;
    fs::path input_folder = "./inputs";
    auto input_day = input_folder / ("day" + std::to_string(day) + ".txt");
    std::fstream input_file{input_day};
    std::string input{std::istream_iterator<char>(input_file), std::istream_iterator<char>()};
    switch(day) {
        case 1 : std::cout << "Day 1:" << std::endl; 
                 do_day(Day1(), input);
                 break;
        default : std::cout << "no such day" << std::endl;
    }
}
