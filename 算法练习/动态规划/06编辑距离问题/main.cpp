#include "editDistance.hpp"
#include <iostream>
#include <string>

int main()
{
    string s = "bag", t = "pack";
    int total_steps = editDistanceDP(s, t);
    cout << "最少步骤为：" << total_steps << endl;

    return 0;
}