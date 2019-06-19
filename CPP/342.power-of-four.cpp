/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (43.93%)
 * Total Accepted:    5.2K
 * Total Submissions: 11.7K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 *
 * 示例 1:
 *
 * 输入: 16
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: 5
 * 输出: false
 *
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 *
 */
class Solution
{
  public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (n == 1 || n == 4)
        {
            return true;
        }
        else
        {
            return (n % 4 == 0) ? isPowerOfFour(n /= 4) : false;
        }
    }
};
