#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
# https://leetcode.com/problems/3sum/description/
#
# algorithms
# Medium (23.67%)
# Total Accepted:    526.1K
# Total Submissions: 2.2M
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# Given an array nums of n integers, are there elements a, b, c in nums such
# that a + b + c = 0? Find all unique triplets in the array which gives the sum
# of zero.
#
# Note:
#
# The solution set must not contain duplicate triplets.
#
# Example:
#
#
# Given array nums = [-1, 0, 1, 2, -1, -4],
#
# A solution set is:
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
#
# 最好时间复杂度 O(n^2)
#
class Solution:
    def threeSum(self, nums):
        # 先睡数据排序
        nums, lens, ret = sorted(nums), len(nums), []
        # 选择第一个数
        for it1 in range(lens - 2):
            # 数据是排好序的，如果第一个数大于0则不可能存在==0的数值
            if nums[it1] > 0:
                break
            # 避免第一个数重复
            if it1 > 0 and nums[it1] == nums[it1 - 1]:
                continue
            # 退化为一个 2 sum 的问题
            # 假设三个数是按顺序选择的，则后两个数是从下一个开始到结束位置
            l, r = it1 + 1, lens - 1
            while l < r:
                s = nums[it1] + nums[l] + nums[r]
                if s == 0:
                    ret.append([nums[it1], nums[l], nums[r]])
                    # 去重
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    # 继续寻找下一组
                    l += 1
                    r -= 1
                elif s < 0:
                    l += 1
                else:
                    r -= 1
        return ret

s = Solution()
ret = s.threeSum([-1, 0, 1, 2, -1, -4])
print(ret)
