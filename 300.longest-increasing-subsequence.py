#
# @lc app=leetcode id=300 lang=python3
#
# [300] Longest Increasing Subsequence
#
# https://leetcode.com/problems/longest-increasing-subsequence/description/
#
# algorithms
# Medium (40.41%)
# Total Accepted:    206.4K
# Total Submissions: 510.7K
# Testcase Example:  '[10,9,2,5,3,7,101,18]'
#
# Given an unsorted array of integers, find the length of longest increasing
# subsequence.
#
# Example:
#
#
# Input: [10,9,2,5,3,7,101,18]
# Output: 4
# Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
# length is 4.
#
# Note:
#
#
# There may be more than one LIS combination, it is only necessary for you to
# return the length.
# Your algorithm should run in O(n^2) complexity.
#
#
# Follow up: Could you improve it to O(n log n) time complexity?
#
# 动态规划
# 定义状态：LIS(i) 表示以第 i 个数字为结尾的最长上升子序列的长度。即在 [0, ..., i] 的范围内，选择以数字 nums[i] 结尾可以获得的最长上升子序列的长度。
# 关键字是：以第 i 个数字为结尾，即我们要求 nums[i] 必须被选取。反正一个子序列一定要以一个数字结尾，那我就将状态这么定义，这一点是重要且常见的。

# 状态转移方程：遍历到索引是 i 的数的时候，我们应该把索引是 [0, ... ,i - 1] 的 LIS 都看一遍，如果当前的数 nums[i] 大于之前的某个数，
# 那么 nums[i] 就可以接在这个数后面形成一个更长的 LIS 。把前面的 i 个数都看了， LIS[i] 就是它们的最大值加 1。即比当前数要小的那些里头，找最大的，然后加 1。

# 状态转移方程即：LIS(i) = max( 1 + LIS(j) if j < i and nums[i] > nums[j])

# 最后不要忘了，应该扫描一遍这个LIS[i]数组，其中最大的就是我们所求的 。

class Solution:
    def lengthOfLIS(self, nums) -> int:
        lens = len(nums)
        # 当长度小于等于1的时候，LIS 就是 nums 本身
        if lens <= 1:
            return lens
        dp = [1] * lens
        # 以 i 结尾的数字
        for i in range(1, lens):
            # i 处的数值比 1-i 的任何一个数值大，都有可能存在更改子序列长度的可能
            # 因为只要把 i 的数值加入就可以变成新的递增子序列
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
