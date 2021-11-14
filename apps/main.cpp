import <iostream>;
import <string>;

import boiler;
import day;


void do_day(AbstractDay& day){
    day.parse();
}


void run_day(int day)
{
    switch(day) {
        case 1 : std::cout << "1" << std::endl; 
                 do_day(Day1());
                 break;
        default : std::cout << "no such day" << std::endl;
    }
}


int main(int argc, char* argv[]){
    if(argc < 2) {
        std::cout << "Usage: " << argv[0] << " " << "<day_number>" << std::endl;
        return -1;
    }
    run_day(std::stoi(argv[1]));
}
