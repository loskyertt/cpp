#include "jumpStairs.hpp"
#include <iostream>

int main()
{
    int n = 4;
    // int ways = jumpStairs(4);
    // int ways = jumpStairsDFS(4);
    // int ways = jumpStairsDFSMem(4);
    // int ways = jumpStairsDP(4);
    int ways = jumpStairsDPComp(4);
    cout << "有" << ways << "种方式" << endl;
    return 0;
}