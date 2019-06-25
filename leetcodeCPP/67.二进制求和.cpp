/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (49.09%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    28.3K
 * Total Submissions: 57.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
// 思路同整数求和
// 竖式计算
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length(), carry = 0;
        string ret;
        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            if (i >= 0) carry += a[i] - '0';
            if (j >= 0) carry += b[j] - '0';
            ret += carry % 2 + '0';
            carry /= 2;
        }
        // 翻转字符串
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

