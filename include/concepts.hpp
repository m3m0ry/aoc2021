#include <string>
#include <concepts>

template<typename T>
concept Day = requires (T a){
    {a.parse("")} -> std::same_as<void>;
    {a.part1()} -> std::convertible_to<std::string>;
    {a.part2()} -> std::convertible_to<std::string>;
};
