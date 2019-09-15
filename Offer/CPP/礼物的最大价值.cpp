#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 礼物的最大价值.cpp
int get_maxvalue(vector<vector<int>>& values)
{
    int m = values.size(), n = values[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    // 初始化
    dp[0][0] = values[0][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = values[0][i] + dp[0][i - 1];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = values[i][0] + dp[i - 1][0];
    }

    // 状态转移
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + values[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int main(void)
{
    vector<vector<int>> mat = { { 1, 10, 3, 8 }, { 12, 2, 9, 6 }, { 5, 7, 4, 11 }, { 3, 7, 16, 5 } };
    cout << get_maxvalue(mat) << endl;
    return 0;
}
