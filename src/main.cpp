#include <iostream>

#include "exceptional.hpp"

using namespace afv;

int main (int argc, char const* argv[]) {
    exceptional<int, float> e (5);
    e
    .and_then<int> (
        [] 
        (int x) -> int { return x + 1; })
    .and_finally ([] (int x) {
        std::cout << x << std::endl;
    });
    return 0;
}
