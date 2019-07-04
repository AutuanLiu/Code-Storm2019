/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (36.16%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    41.7K
 * Total Submissions: 114.8K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */
// 牛顿法
// 求 xn^2 - x = 0
class Solution {
public:
    int mySqrt(int x) {
        double start = 1.0;
        if (x == 0)
            return 0;
        while (true) {
            double new_start = 0.5 * (start + x / start); 
            if (abs((new_start - start)) < 1)
                return int(new_start);
            start = new_start;
        }
    }
};

