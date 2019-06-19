#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        lens, end = len(nums), 0
        for p in range(1, lens):
            if nums[p] != nums[end]:
                end += 1
                nums[end] = nums[p]
        return end + 1 if lens > 0 else end

