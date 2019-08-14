/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (62.20%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 38.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */
// 对于第一行和第一列 [i, j] 只能是从左边或者上边到达
// 那么其最小值就是之前路径的累积和
// 对于其他位置，其可以从左边或者上边到达，取其最小的路径继续前进
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid)
//     {
//         int m = grid.size(), n = grid[0].size();
//         // 第一行和第一列处理
//         for (int i = 1; i < n; i++) {
//             grid[0][i] += grid[0][i - 1];
//         }
//         for (int i = 1; i < m; i++) {
//             grid[i][0] += grid[i - 1][0];
//         }
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
//             }
//         }
//         return grid[m - 1][n - 1];
//     }
// };

// 一维动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        // 初始化为第一行的数值
        vector<int> dp(grid[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = grid[0][i] + dp[i - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 第一列要进行特殊处理
                if (j == 0) {
                    dp[j] = grid[i][j] + dp[j];
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
    }
};
