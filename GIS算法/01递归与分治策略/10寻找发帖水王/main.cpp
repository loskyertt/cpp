#include "find.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> id = { 1,
        2,
        3,
        2,
        2,
        5, 2, 2, 3, 2, 5, 2 };

    int sw = find(id, id.size());

    if (sw != -1) {
        cout << "水王的 id 是：" << sw << endl;
    } else {
        cout << "没有水王。" << endl;
    }

    return 0;
}