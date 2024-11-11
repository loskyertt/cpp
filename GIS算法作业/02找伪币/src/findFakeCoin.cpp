#include "findFakeCoin.hpp"

int compare(const vector<int>& coins, int left, int mid, int right)
{
    int sumLeft = 0, sumRight = 0;

    for (int i = left; i <= mid; i++) {
        sumLeft += coins[i];
    }
    for (int i = mid + 1; i <= right; i++) {
        sumRight += coins[i];
    }

    if (sumLeft < sumRight)
        return 1;
    if (sumLeft > sumRight)
        return -1;
    return 0;
}

int findFakeCoin(const vector<int>& coins, int left, int right)
{
    if (left == right) { // 只有一个硬币，必然是伪币
        return left;
    }

    int mid = left + (right - left) / 2; // 划分成两组
    int result = compare(coins, left, mid, right);

    if (result == 1) { // 左边轻，伪币在左组
        return findFakeCoin(coins, left, mid);
    } else if (result == -1) { // 右边轻，伪币在右组
        return findFakeCoin(coins, mid + 1, right);
    } else { // 两边相等，伪币在未比较的那部分（如果有）
        if ((right - left + 1) % 2 != 0) {
            return right; // 奇数情况下，伪币在最后一个硬币
        }
    }
    return -1; // 未找到
}