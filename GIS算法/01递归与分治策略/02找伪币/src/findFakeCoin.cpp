#include "findFakeCoin.hpp"

int compare(const vector<int>& coins, int left, int mid, int right)
{
    int sumLeft = 0, sumRight = 0;
    int countLeft = 0, countRight = 0;

    for (int i = left; i <= mid; i++) {
        sumLeft += coins[i];
        countLeft++;
    }
    for (int i = mid + 1; i <= right; i++) {
        sumRight += coins[i];
        countRight++;
    }

    if (sumLeft < sumRight) {
        return 1;
    } else if (sumLeft > sumRight) {
        return -1;
    } else {
        if (countLeft > countRight) {
            return 2;
        }
        return 0;
    }
}

int findFakeCoin(const vector<int>& coins, int left, int right)
{
    if (left == right) { // 只有一个硬币，必然是伪币
        return left;
    }

    int mid = left + (right - left) / 2; // 划分成两组
    int result = compare(coins, left, mid, right);

    if (result == 1 || result == 2) { // 左边轻，伪币在左组；还有中情况是当硬币是奇数个，比如[1, 1, 0, 1, 1]，分成的是 [1, 1, 0] 和 [1, 1]，两边重量相等
        return findFakeCoin(coins, left, mid);
    } else if (result == -1) { // 右边轻，伪币在右组
        return findFakeCoin(coins, mid + 1, right);
    }
    return -1; // 未找到伪币
}
