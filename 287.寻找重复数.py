#
# @lc app=leetcode.cn id=287 lang=python3
#
# [287] 寻找重复数
#
# https://leetcode-cn.com/problems/find-the-duplicate-number/description/
#
# algorithms
# Medium (60.60%)
# Likes:    246
# Dislikes: 0
# Total Accepted:    17.2K
# Total Submissions: 28.4K
# Testcase Example:  '[1,3,4,2,2]'
#
# 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
# n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
# 
# 示例 1:
# 
# 输入: [1,3,4,2,2]
# 输出: 2
# 
# 
# 示例 2:
# 
# 输入: [3,1,3,4,2]
# 输出: 3
# 
# 
# 说明：
# 
# 
# 不能更改原数组（假设数组是只读的）。
# 只能使用额外的 O(1) 的空间。
# 时间复杂度小于 O(n^2) 。
# 数组中只有一个重复的数字，但它可能不止重复出现一次。
# 
# 
#

# 首先进行排序
# 遍历数组 如果下一个位置的数值和当前值相等 则重复
# class Solution:
#     def findDuplicate(self, nums: List[int]) -> int:
#         nums = sorted(nums) # 这里开辟了新的空间 存储副本
#         n = len(nums)
#         for i in range(n-1):
#             if nums[i] == nums[i + 1]:
#                 return nums[i]
#         return -1

class Solution(object):
    def findDuplicate(self, nums):
        slow = 0
        fast = 0
    
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
    
            if slow == fast:
                break
    
        finder = 0
        while True:
            slow   = nums[slow]
            finder = nums[finder]
    
            if slow == finder:
                return slow


