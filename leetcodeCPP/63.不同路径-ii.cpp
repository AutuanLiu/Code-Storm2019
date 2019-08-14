/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (31.70%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 54.8K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */
// 首先应该确定边界处的数值
// dp[i, j] 表示从开始到[i, j] 的路径数，若[i, j]处有障碍物则说明，不可以到达该处
// 也即到达该处的路径数为 0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n));
        if (obstacleGrid[0][0] == 1)
            return 0;
        // 先确定边界处的数值
        // 对第一行和第一列来说，一旦某处出现 1 则说明后面的路径均不可到达
        // 对于中间遇到障碍物 只说明不可到达障碍物处
        dp[0][0] = 1; // 交叉项赋值
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0)
                dp[0][i] = 1;
            else {
                // 障碍物及其之后均为 0
                while (i < n) {
                    dp[0][i] = 0;
                    i++;
                }
            }
        }
        // 这里必须要去掉第一个数  因为上面已经处理过了
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else {
                // 障碍物及其之后均为 0
                while (i < m) {
                    dp[i][0] = 0;
                    i++;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0)
                    // 这里有可能会溢出
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }
};
