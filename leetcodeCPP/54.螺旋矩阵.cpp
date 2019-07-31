/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (36.04%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 48.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return {};
        int ub = 0, db = matrix.size() - 1, lb = 0, rb = matrix[0].size() - 1;
        vector<int> ret;
        while (lb <= rb && ub <= db) {
            // 按照顺时针的顺序，即 右->下->左->上 的顺序
            // 向右移动，从左边界到右边界, 维持在上边界的行
            for (int it = lb; it <= rb; it++)
                ret.push_back(matrix[ub][it]);
            if (++ub > db)
                break; // 重新设定上边界，即向下移动一行，如果上下边界重合，那么访问就结束

            // 向下移动到下边界
            for (int it = ub; it <= db; it++)
                ret.push_back(matrix[it][rb]);
            if (--rb < lb)
                break; // 重新设定右边界，如果出现左右边界重合的情况，则迭代停止

            // 向左移动
            for (int it = rb; it >= lb; it--)
                ret.push_back(matrix[db][it]);
            if (--db < ub)
                break;  // 重新定义下边界，如果上下边界重合或者交叉，就停止循环

            // 向上移动
            for (int it = db; it >= ub; it--)
                ret.push_back(matrix[it][lb]);
            if (++lb > rb)
                break;  // 重新定义左边界，如果左右边界重合或者交叉，就停止循环
        }
        return ret;
    }
};
