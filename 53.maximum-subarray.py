#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#
# https://leetcode.com/problems/maximum-subarray/description/
#
# algorithms
# Easy (43.00%)
# Total Accepted:    481.4K
# Total Submissions: 1.1M
# Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
#
# Given an integer array nums, find the contiguous subarray (containing at
# least one number) which has the largest sum and return its sum.
#
# Example:
#
#
# Input: [-2,1,-3,4,-1,2,1,-5,4],
# Output: 6
# Explanation: [4,-1,2,1] has the largest sum = 6.
#
#
# Follow up:
#
# If you have figured out the O(n) solution, try coding another solution using
# the divide and conquer approach, which is more subtle.
#
#
# 关键在于找到开始的位置
# 如果前面的累计和加上当前的数比当前数还小，则从当前数开始的累计和一定比之前的累计和大
# 另外还要考虑负数开头的情况
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum, cur_sum = nums[0], nums[0]
        for item in nums[1:]:
            cur_sum += item
            if cur_sum < item:
                cur_sum = item
            max_sum = max(max_sum, cur_sum)
        return max_sum
