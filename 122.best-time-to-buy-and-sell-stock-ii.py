#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#
# algorithms
# Easy (51.12%)
# Total Accepted:    300K
# Total Submissions: 586.6K
# Testcase Example:  '[7,1,5,3,6,4]'
#
# Say you have an array for which the i^th element is the price of a given
# stock on day i.
#
# Design an algorithm to find the maximum profit. You may complete as many
# transactions as you like (i.e., buy one and sell one share of the stock
# multiple times).
#
# Note: You may not engage in multiple transactions at the same time (i.e., you
# must sell the stock before you buy again).
#
# Example 1:
#
#
# Input: [7,1,5,3,6,4]
# Output: 7
# Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
# 5-1 = 4.
# Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
# 3.
#
#
# Example 2:
#
#
# Input: [1,2,3,4,5]
# Output: 4
# Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
# 5-1 = 4.
# Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
# are
# engaging multiple transactions at the same time. You must sell before buying
# again.
#
#
# Example 3:
#
#
# Input: [7,6,4,3,1]
# Output: 0
# Explanation: In this case, no transaction is done, i.e. max profit = 0.
#
#
# 借助 845 的思路
class Solution:
    def maxProfit(self, prices):
        if not prices:
            return 0
        profit, idx, buy_min, sell_max = 0, 0, prices[0], prices[0]
        while idx < len(prices) - 1:
            while idx < len(prices) - 1 and prices[idx] >= prices[idx + 1]:
                idx += 1
            buy_min = prices[idx]
            while idx < len(prices) - 1 and prices[idx] <= prices[idx + 1]:
                idx += 1
            sell_max = prices[idx]
            profit += sell_max - buy_min

        return profit


s = Solution()
print(s.maxProfit([7, 1, 5, 3, 6, 4]))
print(s.maxProfit([7, 6, 4, 3, 1]))
print(s.maxProfit([1, 2]))
print(s.maxProfit([2, 4, 1]))
print(s.maxProfit([1, 2, 3, 4, 5]))
