/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (55.17%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    30.4K
 * Total Submissions: 55K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 *
 * 说明：m 和 n 的值均不超过 100。
 *
 * 示例 1:
 *
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 *
 *
 * 示例 2:
 *
 * 输入: m = 7, n = 3
 * 输出: 28
 *
 */
// m 列 n 行
// 向右m-1步向下n-1步 从所有的可能中选出 m-1 步
// C(m + n - 2, m - 1)
// DFS
// class Solution {
// public:
//     // 使用迭代的方式计算
//     int uniquePaths(int m, int n)
//     {
//         int N = m + n - 2;
//         double ret = 1.0;
//         int k = min(m, n) - 1;
//         for (int i = 1; i <= k; i++) {
//             // 这里一定要先乘后除，否则可能造成精度的损失
//             ret *= N - k + i;
//             ret /= i; // 考虑无法整除的情况
//         }
//         return int(ret);
//     }
// };

// 动态规划
// 到达[i, j] 时，可能是从上方[i - 1, j]下来的, 也可能是从左边[i, j - 1]过来的
// 所以 dp[i, j] = dp[i - 1, j] + dp[i, j - 1]
// class Solution {
// public:
//     // m列n行
//     int uniquePaths(int m, int n)
//     {
//         // 初始时 都为 1
//         vector<vector<int>> dp(n, vector<int>(m, 1));
//         // 边界处的数值只能为1，所以从非边界处开始计算
//         for (int i = 1; i < n; i++) {
//             for (int j = 1; j < m; j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[n - 1][m - 1];
//     }
// };

// 动态规划
// 到达[i, j] 时，可能是从上方[i - 1, j]下来的, 也可能是从左边[i, j - 1]过来的
// 所以 dp[i, j] = dp[i - 1, j] + dp[i, j - 1]
// 上述动态规划可以化简为一维动态规划
// 对每一行进行原地更新，dp[i - 1, j] 就表示为当前遍历值 dp[i, j - 1]表示为前一个数值
// dp[i, j] 表示为当前要更新的数值
class Solution {
public:
    // m列n行
    int uniquePaths(int m, int n)
    {
        // 初始时 都为 1
        vector<int> dp(m, 1);
        // 边界处的数值只能为1，所以从非边界处开始计算
        // 按行对每列进行更新
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[m - 1];
    }
};
