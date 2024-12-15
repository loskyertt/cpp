#include "Solution.hpp"
#include <vector>

void test()
{
    std::vector<Drink> drinks = { { 10, 3 },
        { 8, 4 },
        { 6, 5 } };
    int target = 7;

    Solution s1;
    s1.distribute(drinks, target);
}

int main()
{
    test();

    return 0;
}