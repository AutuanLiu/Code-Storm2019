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
class Solution
{
public:
    vector<int> getRow(int rowIndex) {
        assert(rowIndex >= 0);
        vector<int> ret;
        long item = 1;

        for (int it = 0; it <= rowIndex; it++) {
            ret.push_back(int(item));
            item = item * (rowIndex - it) / (it + 1);
        }
        return ret;
    }

    int uniquePaths(int m, int n)
    {
        vector<int> nums = getRow(m + n - 2);
        return nums[m - 1];
    }
};
