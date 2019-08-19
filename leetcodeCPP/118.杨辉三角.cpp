/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (63.30%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    30.7K
 * Total Submissions: 48.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// 使用排列组合  超过范围
// class Solution {
// public:
//     long long product(int start, int end)
//     {
//         if (start == 0)
//             return 1;
//         long long ret = 1;
//         for (int it = end + 1; it <= start; it++) {
//             ret *= it;
//         }
//         return ret;
//     }

//     int combination(int m, int n)
//     {
//         if (m == 0 || n == 0)
//             return 1;
//         if (n > m / 2)
//             return combination(m, m - n);
//         return product(m, n) / product(m - n, 1);
//     }

//     vector<vector<int>> generate(int numRows)
//     {
//         if (numRows == 0)
//             return {};
//         vector<vector<int>> ret(numRows);
//         for (int it = 0; it < numRows; it++) {
//             for (int j = 0; j <= it; j++) {
//                 ret[it].push_back(combination(it, j));
//             }
//         }
//         return ret;
//     }
// };

// 排列组合的优化版本
// 超时了
// class Solution {
// public:
//     int combination(int m, int n)
//     {
//         if (m == 0 || n == 0)
//             return 1;
//         if (n > m / 2)
//             return combination(m, m - n);
//         // 排列组合的计算方法
//         return combination(m - 1, n - 1) + combination(m - 1, n);
//     }

//     vector<vector<int>> generate(int numRows)
//     {
//         if (numRows == 0)
//             return {};
//         vector<vector<int>> ret(numRows);
//         for (int it = 0; it < numRows; it++) {
//             for (int j = 0; j <= it; j++) {
//                 ret[it].push_back(combination(it, j));
//             }
//         }
//         return ret;
//     }
// };

// 模拟构造
// 动态规划
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};
        vector<vector<int>> ret(numRows);
        for (int it = 0; it < numRows; it++) {
            for (int j = 0; j <= it; j++) {
                // 初始值和两侧的值衡为1
                if (it < 1 || j == 0 || j == it)
                    ret[it].push_back(1);
                else {
                    int item = ret[it - 1][j - 1] + ret[it - 1][j];
                    ret[it].push_back(item);
                }
            }
        }
        return ret;
    }
};
