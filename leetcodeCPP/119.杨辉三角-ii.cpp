/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (57.19%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 34.1K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
// class Solution {
// public:
//     vector<int> getRow(int rowIndex)
//     {
//         assert(rowIndex >= 0);
//         vector<int> ret(rowIndex + 1, 1);
//         vector<int> tmp(rowIndex + 1, 1);

//         for (int it = 2; it <= rowIndex; it++) {
//             // 遍历到 行索引位置, 并填充每个位置
//             for (int j = 1; j < it; j++) {
//                 ret[j] = tmp[j - 1] + tmp[j];
//             }
//             tmp = ret;
//         }
//         return ret;
//     }
// };

// C(m, n + 1) = C(m, n) * (m - n) / (n + 1)
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        assert(rowIndex >= 0);
        vector<int> ret;
        long item = 1;

        for (int it = 0; it <= rowIndex; it++) {
            ret.push_back(int(item));
            item = item * (rowIndex - it) / (it + 1);
        }
        return ret;
    }
};
