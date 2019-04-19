#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#
# https://leetcode.com/problems/sqrtx/description/
#
# algorithms
# Easy (30.94%)
# Total Accepted:    351.7K
# Total Submissions: 1.1M
# Testcase Example:  '4'
#
# Implement int sqrt(int x).
#
# Compute and return the square root of x, where x is guaranteed to be a
# non-negative integer.
#
# Since the return type is an integer, the decimal digits are truncated and
# only the integer part of the result is returned.
#
# Example 1:
#
#
# Input: 4
# Output: 2
#
#
# Example 2:
#
#
# Input: 8
# Output: 2
# Explanation: The square root of 8 is 2.82842..., and since
# the decimal part is truncated, 2 is returned.
#
# 牛顿法或者二分法
#
class Solution:
    def mySqrt(self, x: int) -> int:
        if 0 <= x <= 1:
            return x
        x0 = 1.
        while True:
            x1 = 0.5 * (x0 + x / x0)
            if abs(x1 - x0) < 1:
                break
            x0 = x1
        return int(x1)
