#include <iostream>
#include <string>

#include "boiler.hpp"

int main(int argc, char* argv[]){
    if(argc < 3) {
        std::cout << "Usage: " << argv[0] << " <day_number> <input>" << std::endl;
        return -1;
    }
    run_day(std::stoi(argv[1]), std::string(argv[2]));
    return 0;
}
