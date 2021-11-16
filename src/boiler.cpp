#include "boiler.hpp"

void run_day(int day)
{
    //fs::path input = "/usr";
    //std::string d = "day" + std::to_string(day) + ".txt";
    //input /= std::string("1");
    //std::cout << input << std::endl; 
    //std::cout << d << std::endl; 
    switch(day) {
        case 1 : std::cout << "1" << std::endl; 
                 do_day(Day1());
                 break;
        default : std::cout << "no such day" << std::endl;
    }
}
