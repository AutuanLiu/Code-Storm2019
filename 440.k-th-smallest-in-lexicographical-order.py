#
# @lc app=leetcode id=440 lang=python3
#
# [440] K-th Smallest in Lexicographical Order
#
# https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
#
# algorithms
# Hard (26.27%)
# Total Accepted:    7.8K
# Total Submissions: 29.6K
# Testcase Example:  '13\n2'
#
# Given integers n and k, find the lexicographically k-th smallest integer in
# the range from 1 to n.
#
# Note: 1 ≤ k ≤ n ≤ 10^9.
#
# Example:
#
# Input:
# n: 13   k: 2
#
# Output:
# 10
#
# Explanation:
# The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so
# the second smallest number is 10.
#
#
#
#
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        from math import log10

        def sumdig(n):
            return 0 if n == 0 else n % 10 + sumdig(n // 10)

        def h(n, m):
            return (10 * n - sumdig(n) - 10**m + 1) // 9 + m

        def kth(k, m):
            G = (10**m - 1) // 9
            x = 1 + (k - 1) // G
            k = (k - 1) % G
            while k != 0:
                G = (G - 1) // 10
                x = 10 * x + (k - 1) // G
                k = (k - 1) % G
            return x

        m = 1 + int(log10(n))

        t = h(n, m)
        if k <= t:
            return kth(k, m)
        return kth(k - t + h(n // 10, m - 1), m - 1)
