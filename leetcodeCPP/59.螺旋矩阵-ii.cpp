/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (73.11%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 17K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0)
            return {};

        // 先指定数组大小 然后才能对相应的位置进行赋值操作
        vector<vector<int>> ret(n, vector<int>(n));
        int ub = 0, db = n - 1, lb = 0, rb = n - 1, v = 1;

        while (lb <= rb && ub <= db) {
            // 向右存放
            for (int it = lb; it <= rb; it++)
                ret[ub][it] = v++;
            if (++ub > db)
                break;

            // 向下存放
            for (int it = ub; it <= db; it++)
                ret[it][rb] = v++;
            if (--rb < lb)
                break;

            // 向左存放
            for (int it = rb; it >= lb; it--)
                ret[db][it] = v++;
            if (--db < ub)
                break;

            // 向上存放
            for (int it = db; it >= ub; it--)
                ret[it][lb] = v++;
            if (++lb > rb)
                break;
        }
        return ret;
    }
};
