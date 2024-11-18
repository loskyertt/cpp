#include "generateSubsets.hpp"
#include <string>
#include <vector>

int main()
{
    vector<string> E = { "a", "b", "c" }; // 原始集合
    // generateSubsets(E);
    generateSubsetsBin(E);
    return 0;
}