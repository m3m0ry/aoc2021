#include <iostream>
#include <string>

#include "boiler.hpp"

int main(int argc, char* argv[]){
    if(argc < 2) {
        std::cout << "Usage: " << argv[0] << " " << "<day_number>" << std::endl;
        return -1;
    }
    run_day(std::stoi(argv[1]));
    return 0;
}
