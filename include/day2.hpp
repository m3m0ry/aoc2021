#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <unordered_map>

enum dir { forward, down, up };

static std::unordered_map<std::string,dir> const table = {{"forward", dir::forward}, {"down",dir::down}, {"up", dir::up}};

struct Day2{
    void parse(std::vector<std::string> input);
    std::string part1() const;
    std::string part2() const;
    std::vector<std::pair<dir, int>> movement;
};
