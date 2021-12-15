#pragma once
#include <iostream>
#include <chrono>

#include <concepts.hpp>

template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}


// TODO How do I make this work without T specialization
template<Printable T>
void show(const T& a){
    std::cout << a << std::endl;
}

