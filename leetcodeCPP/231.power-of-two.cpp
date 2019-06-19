/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (43.71%)
 * Total Accepted:    11.2K
 * Total Submissions: 25.6K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 *
 * 示例 1:
 *
 * 输入: 1
 * 输出: true
 * 解释: 20 = 1
 *
 * 示例 2:
 *
 * 输入: 16
 * 输出: true
 * 解释: 24 = 16
 *
 * 示例 3:
 *
 * 输入: 218
 * 输出: false
 *
 */
class Solution {
  public:
    bool isPowerOfTwo(int n){
        if (n <= 0){
            return false;
        }
        if (n == 1 || n == 2){
            return true;
        }
        else{
            return (n % 2 == 0) ? isPowerOfTwo(n /= 2) : false;
        }
    }
};
