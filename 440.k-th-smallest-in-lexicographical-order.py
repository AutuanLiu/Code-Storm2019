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
# class Solution:
#     def findKthNumber(self, n: int, k: int) -> int:
#         from math import log10

#         def sumdig(n):
#             return 0 if n == 0 else n % 10 + sumdig(n // 10)

#         def h(n, m):
#             return (10 * n - sumdig(n) - 10**m + 1) // 9 + m

#         def kth(k, m):
#             G = (10**m - 1) // 9
#             x = 1 + (k - 1) // G
#             k = (k - 1) % G
#             while k != 0:
#                 G = (G - 1) // 10
#                 x = 10 * x + (k - 1) // G
#                 k = (k - 1) % G
#             return x

#         m = 1 + int(log10(n))

#         t = h(n, m)
#         if k <= t:
#             return kth(k, m)
#         return kth(k - t + h(n // 10, m - 1), m - 1)

# 使用类似于二分查找的思路
# class Solution:
#     def findKthNumber(self, n: int, k: int) -> int:
#         cur = 1
#         k = k - 1
#         # 当 k - 1 = 0 的时候，最小值为 1
#         while k > 0:
#             # 找到目标值所在的区间
#             steps = self.calSteps(n, cur)
#             # 如果小于 k 则在右边，否则在在边
#             if steps <= k:
#                 cur += 1
#                 k -= steps
#             else:
#                 cur *= 10
#                 k -= 1
#         return cur

#     def calSteps(self, n, cur):
#         steps = 0
#         n1, n2 = cur, cur + 1
#         while n1 <= n:
#             steps += min(n + 1, n2) - n1
#             n1 *= 10
#             n2 *= 10
#         return steps


# 使用 DFS(超时)
class Solution:
    def __init__(self):
        self.res = []
        self.max_n = 0

    def findKthNumber(self, n: int, k: int) -> int:
        self.max_n = n
        # 第一层
        for i in range(1, 10):
            if i <= self.max_n:
                self.res.append(i)
                self.dfs(10 * i)
            else:
                break
        return self.res[k - 1]

    def dfs(self, start):
        for offset in range(10):
            cur_num = start + offset
            if cur_num <= self.max_n:
                self.res.append(cur_num)
                self.dfs(cur_num * 10)
            else:
                break
