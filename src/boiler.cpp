export module boiler;

import <string_view>;

export class AbstractDay {
  public:
    virtual ~AbstractDay() = default;
    virtual void parse(std::string_view input) = 0;
    virtual void part1() const = 0;
    virtual void part2() const = 0;
};
