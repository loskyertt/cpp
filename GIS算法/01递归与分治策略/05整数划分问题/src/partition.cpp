#include "partition.hpp"
#include <vector>

int partition(int n, int m)
{
    // 边界条件
    if (n == 1 || m == 1) {
        return 1;
    }

    // 非边界条件
    if (n < m) {
        return partition(n, n);
    } else if (n == m) {
        return 1 + partition(n, m - 1);
    } else {
        return partition(n - m, m) + partition(n, m - 1);
    }
}

int partitionDP(int n, int m)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (i < j) {
                dp[i][j] = dp[i][i];
            } else if (i == j) {
                dp[i][j] = dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n][m];
}