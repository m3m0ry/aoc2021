#include "boiler.hpp"

#include <fstream>
#include <iterator>

namespace fs = std::filesystem;

void run_day(int day, const std::string& input_file)
{
    namespace fs = std::filesystem;
    fs::path input_day = input_file;
    std::fstream filein{input_day};
    std::vector<std::string> input;
    for (std::string line; std::getline(filein, line); ) {
        input.push_back(line);
    }
    switch(day) {
        case 1 : std::cout << "Day 1:" << std::endl; 
                 do_day<Day1>(input);
                 break;
        default : std::cout << "no such day" << std::endl;
    }
}


