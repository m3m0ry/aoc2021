export module day1;

import <vector>;
import <string_view>;
import <iostream>;

import boiler;

export class Day1: AbstractDay {
    public:
        virtual ~Day1() = default;
        virtual void parse(std::string_view input) override {
            std::cout << input << std::endl;
        }
        virtual void part1() const override {
            std::cout << "part1" << std::endl;
        }
        virtual void part2() const override {
            std::cout << "part1" << std::endl;
        }
    private:
        std::vector<int> numbers;
};
