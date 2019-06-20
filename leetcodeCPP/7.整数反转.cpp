/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (32.52%)
 * Likes:    1097
 * Dislikes: 0
 * Total Accepted:    135.7K
 * Total Submissions: 417.4K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 示例 1:
 *
 * 输入: 123
 * 输出: 321
 *
 *
 * 示例 2:
 *
 * 输入: -123
 * 输出: -321
 *
 *
 * 示例 3:
 *
 * 输入: 120
 * 输出: 21
 *
 *
 * 注意:
 *
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 *
 */

// C++ INT_MAX 2147483647  INT_MIN  -2147483648
// 反转的一般思路 不断取余然后除10
// 对于数字x
// remainder = x % 10
// ret = ret * 10 + remainder
// 主要在于判断 ret 是否溢出

class Solution
{
public:
    int reverse(int x){
        int ret = 0;
        while (x){
            int remainder = x % 10;
            // 溢出的话，就先截断返回
            // 在乘之前就判断是否溢出
            // 7 = INT_MAX % 10, -8 = INT_MIN % 10
            // 正数
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && remainder > 7))
                return 0;
            // 负数
            if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && remainder < -8))
                return 0;
            ret = ret * 10 + remainder;
            x /= 10;
        }
        return ret;
    }
};
