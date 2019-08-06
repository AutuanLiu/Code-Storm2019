/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (74.69%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 9.5K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution {
public:
    bool isValid(int row, int col, const vector<int>& solutions)
    {
        for (int i = 0; i < row; i++) {
            // 不同列 不同对角线
            if (col == solutions[i] || abs(col - solutions[i]) == abs(i - row))
                return false;
        }
        return true;
    }

    void solveNQueensRecursive(int n, int row, vector<int>& solutions, int& ret)
    {
        // 递归出口
        if (row == n) {
            ret++;
            return;
        }

        for (int cur_col = 0; cur_col < n; cur_col++) {
            if (isValid(row, cur_col, solutions)) {
                solutions[row] = cur_col;
                solveNQueensRecursive(n, row + 1, solutions, ret);
            }
        }
    }

    int totalNQueens(int n)
    {
        vector<int> solutions(n);
        int ret = 0;
        solveNQueensRecursive(n, 0, solutions, ret);
        return ret;
    }
};
