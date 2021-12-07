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
    std::cout << "Day " << day << ":" << std::endl;
    switch(day) {
        case 1 : do_day<Day1>(input);
                 break;
        case 2 : do_day<Day2>(input);
                 break;
        case 3 : do_day<Day3>(input);
                 break;
        case 4 : do_day<Day4>(input);
                 break;
        case 5 : do_day<Day5>(input);
                 break;
        case 6 : do_day<Day6>(input);
                 break;
        case 7 : do_day<Day7>(input);
                 break;
        //case 8 : do_day<Day8>(input);
        //         break;
        //case 9 : do_day<Day9>(input);
        //         break;
        default : std::cout << "no such day" << std::endl;
    }
}


