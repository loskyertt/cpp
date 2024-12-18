#include "Solution.hpp"
#include <iostream>
#include <vector>

void test()
{
    std::vector<Activity> activities = { { 1, 3 },
        { 2, 5 },
        { 4, 6 },
        { 7, 9 },
        { 6, 7 },
        { 5, 8 } };

    Solution s1;
    std::vector<Activity> res = s1.selectActivites(activities);

    for (auto activity : res) {
        std::cout << "{ " << activity.start << ", " << activity.end << " }" << std::endl;
    }
}

int main()
{
    test();

    return 0;
}