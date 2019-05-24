#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
class Solution1:
    def twoSum(self, nums, target: int):
        hash, ret = {}, []
        for idx, item in enumerate(nums):
            if item not in hash:
                hash[item] = idx
            v = target - item
            # 同一个数值不可以使用多次
            if v in hash and idx != hash[v]:
                ret = [idx, hash[v]]
                break
        return ret

class Solution:
    def twoSum(self, nums, target: int):
        hash, ret = {}, []
        for idx, item in enumerate(nums):
            v = target - item
            # 同一个数值不可以使用多次
            if v in hash:
                ret = [idx, hash[v]]
                break
            hash[item] = idx
        return ret

s = Solution()
print(s.twoSum([3, 3], 6))
