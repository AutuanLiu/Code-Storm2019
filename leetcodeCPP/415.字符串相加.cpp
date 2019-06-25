/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (45.80%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 18.7K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int i = m - 1, j = n - 1, carry = 0;
        string ret = "";
        while (j >= 0 || i >= 0 || carry != 0) {
            if (i >= 0) carry += num1[i--] - '0';
            if (j >= 0) carry += num2[j--] - '0';
            ret += carry % 10 + '0';
            carry /= 10;
        }

        // 翻转字符串
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

