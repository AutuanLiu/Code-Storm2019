#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#
# https://leetcode.com/problems/4sum/description/
#
# algorithms
# Medium (30.03%)
# Total Accepted:    225.6K
# Total Submissions: 746.7K
# Testcase Example:  '[1,0,-1,0,-2,2]\n0'
#
# Given an array nums of n integers and an integer target, are there elements
# a, b, c, and d in nums such that a + b + c + d = target? Find all unique
# quadruplets in the array which gives the sum of target.
#
# Note:
#
# The solution set must not contain duplicate quadruplets.
#
# Example:
#
#
# Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
#
# A solution set is:
# [
# ⁠ [-1,  0, 0, 1],
# ⁠ [-2, -1, 1, 2],
# ⁠ [-2,  0, 0, 2]
# ]
#
#
#
class Solution1:
    def fourSum(self, nums, target: int):
        nums, ret, lens = sorted(nums), [], len(nums)
        if lens < 4:
            return ret
        for it1 in range(lens - 3):
            # 去重
            if it1 > 0 and nums[it1] == nums[it1 - 1]:
                continue
            # 最小的四个数的和大于 target
            if nums[it1] + nums[it1 + 1] + nums[it1 + 2] + nums[it1 + 3] > target:
                break
            if nums[it1] + nums[lens - 3] + nums[lens - 2] + nums[lens - 1] < target:
                continue
            for it2 in range(it1 + 1, lens - 2):
                # 去重
                if it2 > it1 + 1 and nums[it2] == nums[it2 - 1]:
                    continue
                if nums[it1] + nums[it2] + nums[it2 + 1] + nums[it2 + 2] > target:
                    break
                # 当前的数加上最小的数还是比target小，则应当继续增大数值，进行下一组数据
                if nums[it1] + nums[it2] + nums[lens - 2] + nums[lens - 1] < target:
                    continue
                l, r = it2 + 1, lens - 1
                while l < r:
                    s = nums[l] + nums[r] + nums[it1] + nums[it2]
                    if s == target:
                        ret.append([nums[it1], nums[it2], nums[l], nums[r]])
                        # 去重
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        # 继续寻找下一组
                        l += 1
                        r -= 1
                    elif s < target:
                        l += 1
                    else:
                        r -= 1
        return ret

# s = Solution1()
# ret = s.fourSum([2, 1, 0, -1], 2)
# print(ret)

# round 2
class Solution:
    def fourSum(self, nums, target: int):
        nums, ret, lens = sorted(nums), [], len(nums)
        if lens < 4:
            return ret
        for a_id in range(lens - 3):
            # 去重
            if a_id > 0 and nums[a_id] == nums[a_id - 1]:
                continue
            for b_id in range(a_id + 1, lens - 2):
                # 去重
                if b_id > a_id + 1 and nums[b_id] == nums[b_id - 1]:
                    continue
                # 接下来是左右指针搜索的问题
                l, r, v = b_id + 1, lens - 1, target - nums[a_id] - nums[b_id]
                while l < r:
                    if nums[l] + nums[r] < v:
                        l += 1
                    elif nums[l] + nums[r] > v:
                        r -= 1
                    else:
                        ret.append([nums[a_id], nums[b_id], nums[l], nums[r]])
                        # 去重
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        # 这个地方要先去重在进行下一次迭代，不然就会忽略一次重复
                        l += 1
                        r -= 1
        return ret

s = Solution()
ret = s.fourSum([1, 0, -1, 0, -2, 2], 0)
print(ret)
