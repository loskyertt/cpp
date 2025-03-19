#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find_mid_num(vector<int>& A, vector<int>& B, int n)
{
    int leftA = 0, rightA = n - 1;
    int leftB = 0, rightB = n - 1;

    while (leftA < rightA || leftB < rightB) {
        int midA = (leftA + rightA) / 2;
        int midB = (leftB + rightB) / 2;

        if (A[midA] == B[midB]) {
            return A[midA];
        }

        if (A[midA] < B[midB]) {
            if ((rightA - leftA) % 2 == 0) { // 偶数
                leftA = midA; // 这里要保留 midA
                rightB = midB; // 这里收缩到 midB
            } else { // 奇数
                leftA = midA + 1; // 向右移动
                rightB = midB; // 保持 midB
            }
        } else {
            if ((rightB - leftB) % 2 == 0) { // 偶数
                leftB = midB;
                rightA = midA;
            } else { // 奇数
                leftB = midB + 1;
                rightA = midA;
            }
        }
    }

    return min(A[leftA], B[leftB]);
}

int main()
{
    vector<int> A = { 11, 13, 15, 17, 19 };
    vector<int> B = { 2, 4, 6, 8, 20 };

    int n = A.size();
    cout << "中位数：" << find_mid_num(A, B, n) << endl;

    return 0;
}
