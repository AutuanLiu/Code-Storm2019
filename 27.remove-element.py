#
# @lc app=leetcode id=27 lang=python3
#
# [27] Remove Element
#
class Solution:
    def removeElement(self, nums, val: int) -> int:
        lens, end = len(nums), 0
        for p in range(lens):
            if nums[p] != val:
                nums[end] = nums[p]
                end += 1
        # print(nums)
        return end

s = Solution()
ret = s.removeElement([3, 2, 2, 3], 2)
print(ret)
