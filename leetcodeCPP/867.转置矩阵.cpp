/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 *
 * https://leetcode-cn.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (65.07%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 17.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个矩阵 A， 返回 A 的转置矩阵。
 * 
 * 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2,3],[4,5,6]]
 * 输出：[[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A)
    {
        int m = A.size(), n = A[0].size();
        if (m == 0)
            return A;
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret[j][i] = A[i][j];
            }
        }
        return ret;
    }
};
