#
# @lc app=leetcode id=56 lang=python3
#
# [56] Merge Intervals
#
# https://leetcode.com/problems/merge-intervals/description/
#
# algorithms
# Medium (35.17%)
# Total Accepted:    330.8K
# Total Submissions: 935.9K
# Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
#
# Given a collection of intervals, merge all overlapping intervals.
#
# Example 1:
#
#
# Input: [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
# [1,6].
#
#
# Example 2:
#
#
# Input: [[1,4],[4,5]]
# Output: [[1,5]]
# Explanation: Intervals [1,4] and [4,5] are considered overlapping.
#
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
#
#
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        if len(intervals) <= 1:
            return intervals
        items = sorted(intervals, key=lambda x: x[0])
        for item in items:
            if ret == [] or item[0] > ret[-1][1]:
                ret.append(item)
            else:
                ret[-1][1] = max(ret[-1][1], item[1])
        return ret
