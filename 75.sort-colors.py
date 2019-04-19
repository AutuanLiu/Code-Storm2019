#
# @lc app=leetcode id=75 lang=python3
#
# [75] Sort Colors
#
# https://leetcode.com/problems/sort-colors/description/
#
# algorithms
# Medium (41.62%)
# Total Accepted:    306.7K
# Total Submissions: 733.7K
# Testcase Example:  '[2,0,2,1,1,0]'
#
# Given an array with n objects colored red, white or blue, sort them in-place
# so that objects of the same color are adjacent, with the colors in the order
# red, white and blue.
#
# Here, we will use the integers 0, 1, and 2 to represent the color red, white,
# and blue respectively.
#
# Note: You are not suppose to use the library's sort function for this
# problem.
#
# Example:
#
#
# Input: [2,0,2,1,1,0]
# Output: [0,0,1,1,2,2]
#
# Follow up:
#
#
# A rather straight forward solution is a two-pass algorithm using counting
# sort.
# First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
# array with total number of 0's, then 1's and followed by 2's.
# Could you come up with a one-pass algorithm using only constant space?
#
#
#
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        self.sort(nums, 0, len(nums) - 1)    # 排序

    def partition(self, nums, start, end):
        """找到分割点的同时进行排序"""
        i = start - 1
        pivot = nums[end]    # 使用最后的一个元素作为分割元素
        for j in range(start, end):
            if nums[j] < pivot:
                i = i + 1
                # 如果找到比基准元素小的就交换
                nums[i], nums[j] = nums[j], nums[i]
        # 遍历一遍即以找到基准位置 i+1, 之后填入基准元素
        nums[i + 1], nums[end] = nums[end], nums[i + 1]
        return i + 1

    def sort(self, nums, start, end):
        if start < end:
            p = self.partition(nums, start, end)    # 找到分割位置
            self.sort(nums, start, p - 1)    # 左半边排序
            self.sort(nums, p + 1, end)    # 右半边排序
