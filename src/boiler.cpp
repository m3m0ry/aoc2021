#include "boiler.hpp"

#include <fstream>
#include <iterator>

namespace fs = std::filesystem;

void run_day(int day, const std::string& input_file)
{
    namespace fs = std::filesystem;
    fs::path input_day = input_file;
    std::fstream file{input_day};
    std::stringstream stream;
    stream << file.rdbuf();
    std::string input = stream.str();
    //std::string input{std::istream_iterator<char>(file), std::istream_iterator<char>()};
    switch(day) {
        case 1 : std::cout << "Day 1:" << std::endl; 
                 do_day(Day1(), input);
                 break;
        default : std::cout << "no such day" << std::endl;
    }
}
