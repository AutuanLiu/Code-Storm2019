/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (63.06%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 14.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

// https://github.com/MaigoAkisame/Queens/tree/master/python
// https://zhuanlan.zhihu.com/p/51882471
// https://zhuanlan.zhihu.com/p/54098938
// 任两个皇后都不能处于同一条横行、纵行或斜线上、
// 当且仅当n = 1或n ≥ 4时问题有解
// 回溯法是一个树结构
class Solution {
public:
    // 当前位置（row, col）是否可以放皇后
    bool isValid(int row, int col, const vector<int>& solutions)
    {
        // 要检查当前行之前的所有皇后位置是否冲突 不包含当前行 因为还没有放皇后
        // 所以不存在行冲突，比较列冲突和对角线冲突 |x'-x| == |y'-y|, (x',y')是皇后放置的位置
        for (int i = 0; i < row; i++) {
            if (col == solutions[i] || abs(col - solutions[i]) == abs(i - row))
                return false;
        }
        return true;
    }

    void solveNQueensRecursive(int n, int row, vector<int>& solutions, vector<vector<string>>& ret)
    {
        // 递归出口
        if (row == n) {
            vector<string> tmp(n, string(n, '.')); // n * n 字符矩阵 注意是字符
            for (int cur_row = 0; cur_row < n; cur_row++) {
                tmp[cur_row][solutions[cur_row]] = 'Q'; // 字符串中的字符赋值
            }
            ret.push_back(tmp); // 获得一个有效解
            return;
        }

        // 递归解决每一行，对每一行搜索每一列
        for (int col = 0; col < n; col++) {
            // 判断当前位置是否可以放置皇后， 如果可以就放置，否则就继续进行搜索
            if (isValid(row, col, solutions)) {
                // 这两句是包含在当前位置有效的前提下的
                // 只有之前行都有效才能继续搜索下一行
                solutions[row] = col;
                // 递归搜索下一行
                solveNQueensRecursive(n, row + 1, solutions, ret);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ret; // 存储最后的放置位置
        vector<int> solutions(n); // 存储每行皇后放置的位置
        solveNQueensRecursive(n, 0, solutions, ret);
        return ret;
    }
};
