#
# @lc app=leetcode id=16 lang=python3
#
# [16] 3Sum Closest
#
# https://leetcode.com/problems/3sum-closest/description/
#
# algorithms
# Medium (42.20%)
# Total Accepted:    326.5K
# Total Submissions: 737.4K
# Testcase Example:  '[-1,2,1,-4]\n1'
#
# Given an array nums of n integers and an integer target, find three integers
# in nums such that the sum is closest to target. Return the sum of the three
# integers. You may assume that each input would have exactly one solution.
#
# Example:
#
#
# Given array nums = [-1, 2, 1, -4], and target = 1.
#
# The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#
#
#
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums, lens = sorted(nums), len(nums)
        # 假设最少有三个数
        ret = nums[0] + nums[1] + nums[2]
        for it in range(lens - 2):
            l, r = it + 1, lens - 1
            while l < r:
                s = nums[l] + nums[r] + nums[it]
                if s == target:
                    # 直接结束 不用继续下一组
                    return target

                if abs(s - target) < abs(ret - target):
                    ret = s

                if s < target:
                    l += 1
                else:
                    r -= 1
        return ret
