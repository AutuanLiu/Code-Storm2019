#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 0-1 背包问题动态规划解法
int get_score(vector<int>& C, vector<int>& V, int n, int m)
{
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= C[i]; j--) {
            // 状态转移方程
            dp[j] = max(V[i] + dp[j - C[i]], dp[j]);
        }
    }
    return dp[m];
}

int main(void)
{
    int t, n, m;
    cin >> t; // 学弟学妹的人数
    for (int i = 0; i < t; i++) {
        cin >> n >> m; // 该学弟学妹相关的知识点数量和TA准备的总时间
        vector<int> C(n), V(n);
        for (int j = 0; j < n; j++) {
            cin >> C[j] >> V[j];
        }
        cout << get_score(C, V, n, m) << endl;
    }
    return 0;
}
