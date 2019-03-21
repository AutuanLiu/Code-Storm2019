#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#
# algorithms
# Easy (46.46%)
# Total Accepted:    452K
# Total Submissions: 972.8K
# Testcase Example:  '[7,1,5,3,6,4]'
#
# Say you have an array for which the i^th element is the price of a given
# stock on day i.
#
# If you were only permitted to complete at most one transaction (i.e., buy one
# and sell one share of the stock), design an algorithm to find the maximum
# profit.
#
# Note that you cannot sell a stock before you buy one.
#
# Example 1:
#
#
# Input: [7,1,5,3,6,4]
# Output: 5
# Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
# 6-1 = 5.
# Not 7-1 = 6, as selling price needs to be larger than buying price.
#
#
# Example 2:
#
#
# Input: [7,6,4,3,1]
# Output: 0
# Explanation: In this case, no transaction is done, i.e. max profit = 0.
#
#
#
class Solution:
    def maxProfit(self, prices):
        if len(prices) == 0:
            return 0
        buy_min, sell_max, profit_max = prices[0], prices[0], 0
        for idx in range(1, len(prices)):
            # 记录最早的最小值
            if prices[idx] < buy_min:
                buy_min, sell_max = prices[idx], prices[idx]
            else:
                sell_max = max(sell_max, prices[idx])
            # 对每一次移动计算一下当前最大收益
            profit_max = max(profit_max, sell_max - buy_min)
        return profit_max

# s = Solution()
# print(s.maxProfit([7, 1, 5, 3, 6, 4]))
# print(s.maxProfit([7, 6, 4, 3, 1]))
# print(s.maxProfit([1, 2]))
# print(s.maxProfit([2, 4, 1]))
