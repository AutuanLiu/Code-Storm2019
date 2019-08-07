/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (18.49%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 90.2K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 
 * 说明:
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor)
    {

        if (dividend == 0)
            return 0;

        // 判断符号
        int sign = (dividend ^ divisor) < 0 ? -1 : 1;
        
        //  转换为long long型计算，防止 INT32_MIN / -1 溢出
        long long dvd = dividend, dvs = divisor;
        long long cur_bit = 1, ret = 0;

        //  转换为整数计算，最后判断符号
        dvd = abs(dvd);
        dvs = abs(dvs);

        //  先将被除数放大 cur_bit 倍
        //  但是要保证被除数 <= 除数
        while (dvd >= dvs << 1) {
            dvs <<= 1;
            cur_bit <<= 1;
        }

        //  除数依次减去被除数的 cur_bit 倍
        //  右移 cur_bit 循环执行减法
        //  直到 除数为 0 或者 cur_bit == 0
        while (cur_bit > 0 && dvd > 0) {
            if (dvd >= dvs) {
                dvd -= dvs;
                ret += cur_bit;
            }
            cur_bit >>= 1;
            dvs >>= 1;
        }

        //  判断 ret 符号
        ret = sign * ret;

        //  判断是否会溢出，并返回结果
        if (ret > INT32_MAX)
            return INT32_MAX;
        return (int)ret;
    }
};
