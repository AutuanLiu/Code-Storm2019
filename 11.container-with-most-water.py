#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#
# https://leetcode.com/problems/container-with-most-water/description/
#
# algorithms
# Medium (43.36%)
# Total Accepted:    350.9K
# Total Submissions: 800.9K
# Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
#
# Given n non-negative integers a1, a2, ..., an , where each represents a point
# at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
# of line i is at (i, ai) and (i, 0). Find two lines, which together with
# x-axis forms a container, such that the container contains the most water.
#
# Note: You may not slant the container and n is at least 2.
#
#
#
#
#
# The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
# this case, the max area of water (blue section) the container can contain is
# 49.
#
#
#
# Example:
#
#
# Input: [1,8,6,2,5,4,8,3,7]
# Output: 49
#
#
class Solution:
    def maxArea(self, height: List[int]) -> int:
        area, left, right = 0, 0, len(height) - 1
        while left < right:
            area = max(area, (right - left) * min(height[left], height[right]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return area

s = Solution()
ret = s.maxArea([1,8,6,2,5,4,8,3,7])
print(ret)
