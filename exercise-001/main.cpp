#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"
//.bss segment
int foo;
int var;
// .data segment
int data =4711;
int datavar=6969;
// .rodata segment
const int rodata =42;
const int rodatavar=420;

auto main(int argc, char **argv) -> int
{

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Value of variable foo {} address of variable foo {}\n", foo, fmt::ptr(&foo));
    fmt::print("Value of variable data {} address of variable data {}\n", data, fmt::ptr(&data));
    fmt::print("Value of variable rodata {} address of variable rodata {}\n", rodata, fmt::ptr(&rodata));

    fmt::print("Value of variable var {} address of variable var {}\n", var, fmt::ptr(&var));
    fmt::print("Value of variable datavar {} address of variable datavar {}\n", datavar, fmt::ptr(&datavar));
    fmt::print("Value of variable rodatavar {} address of variable rodatavar {}\n", rodatavar, fmt::ptr(&rodatavar));

    return 0; /* exit gracefully*/
}
