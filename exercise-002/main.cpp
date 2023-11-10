#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

void printVec(const std::vector<int>& v); 
auto main(int argc, char **argv) -> int
{
    int count=20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "set counter");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> v(count);
    printVec(v);
    for(int i=0;i<count;i++)
    {
        v[i]=((rand() %100)+1);
    }
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    printf("%d\n", count);
    printVec(v);
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}


void printVec(const std::vector<int>& v) {
    fmt::print("{}\n", fmt::join(v, ", "));
}