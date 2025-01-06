#include "nQueens.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    vector<vector<vector<string>>> res;
    int n = 4;
    res = nQueens(n);

    for (vector<vector<string>> sub_res1 : res) {
        for (vector<string> sub_res2 : sub_res1) {
            for (string i : sub_res2) {
                cout << i;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}