/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 *
 * https://leetcode-cn.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (42.24%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    2K
 * Total Submissions: 4.7K
 * Testcase Example:  '[4,14,2]'
 *
 * 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
 * 
 * 计算一个数组中，任意两个数之间汉明距离的总和。
 * 
 * 示例:
 * 
 * 
 * 输入: 4, 14, 2
 * 
 * 输出: 6
 * 
 * 解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
 * 所以答案为：
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 * 
 * 
 * 注意:
 * 
 * 
 * 数组中元素的范围为从 0到 10^9。
 * 数组的长度不超过 10^4。
 * 
 * 
 */
// O(n^2) 超时
// class Solution {
// public:
//     int hammingDistance(int x, int y)
//     {
//         long long z = (x ^ y);
//         int ret = 0;
//         while (z != 0) {
//             z = (z & (z - 1));
//             ret++;
//         }
//         return ret;
//     }

//     int totalHammingDistance(vector<int>& nums)
//     {
//         int ret = 0, n = nums.size();
//         // 遍历所有的两两组合
//         // 容易超时
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 ret += hammingDistance(nums[i], nums[j]);
//             }
//         }
//         return ret;
//     }
// };

// O(n) 复杂度
// 按位操作 总共遍历32次
// 复杂度是 O(32 * n) = O(n)
// 统计每位1的个数和0的个数
// 按照每位的不同将数组分为两部分 一部分是i位为1，一部分是i位为0
// 两两组合 即其个数相乘
class Solution {
public:
    int totalHammingDistance(vector<int>& nums)
    {
        int n = nums.size(), ret = 0;
        unsigned int mask = 1;  // 无符号整型就够了
        for (int i = 0; i < 32; i++) {
            int cnt1 = 0; // 当前位是1的数值个数
            for (const int& num : nums) {
                if (num & mask)
                    cnt1++;
            }
            ret += cnt1 * (n - cnt1);
            mask <<= 1; // 表示下一位是否是 1
        }
        return ret;
    }
};
