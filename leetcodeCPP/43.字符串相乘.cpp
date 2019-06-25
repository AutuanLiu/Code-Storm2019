/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (39.33%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    18.1K
 * Total Submissiret: 45.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */
// 竖式计算
// 时间复杂度: O(m*n)
// 空间复杂度 : O(m + n)
// m位数乘以n位数的结果不会超过m+n, 最大为 m+n-1位，为了保存进位使用 m+n 个空间
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        string ret(m + n, '0');  // 所有的进位初始化为 '0'
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // 进位和乘积的和，当前要加上上一步计算的进位
                int sum = (ret[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                ret[i + j + 1] = (sum % 10) + '0';  // 保存当前计算的数字(低位)
                ret[i + j] += sum / 10;  // 更新当前进位(高位)
            }
        }

        // 从第一个不为 '0' 的字符开始是有效结果或者结果是个位数
        for (int i = 0; i < ret.length(); i++) {
            if (ret[i] != '0' || i == ret.length() - 1)
                return ret.substr(i);  // 从 i 到最后的子字符串
        }
        return "0";
    }
};

