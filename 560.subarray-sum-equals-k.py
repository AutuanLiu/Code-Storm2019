#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#
# https://leetcode.com/problems/subarray-sum-equals-k/description/
#
# algorithms
# Medium (41.80%)
# Total Accepted:    87.4K
# Total Submissions: 209K
# Testcase Example:  '[1,1,1]\n2'
#
# Given an array of integers and an integer k, you need to find the total
# number of continuous subarrays whose sum equals to k.
#
# Example 1:
#
# Input:nums = [1,1,1], k = 2
# Output: 2
#
#
#
# Note:
#
# The length of the array is in range [1, 20,000].
# The range of numbers in the array is [-1000, 1000] and the range of the
# integer k is [-1e7, 1e7].
#
#
#
#
class Solution:
    def subarraySum(self, nums, k: int) -> int:
        if len(nums) < 1:
            return 0
        cnt, sums = 0, [0] * (len(nums) + 1)
        for idx in range(1, len(nums) + 1):
            sums[idx] = sums[idx - 1] + nums[idx - 1]
        for idx in range(len(nums)):
            for idx1 in range(idx + 1, len(nums) + 1):
                if sums[idx1] - sums[idx] == k:
                    cnt += 1
        return cnt


s = Solution()
print(s.subarraySum([-1, -1, 1], 0))
print(s.subarraySum([1, 2, 3], 3))
print(s.subarraySum([1, 1, 1], 2))
print(s.subarraySum([100, 1, 2, 3, 100, 1, 2, 3, 4], 3))
print(s.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))
print(s.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))
