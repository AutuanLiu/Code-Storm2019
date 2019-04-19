#
# @lc app=leetcode id=57 lang=python3
#
# [57] Insert Interval
#
# https://leetcode.com/problems/insert-interval/description/
#
# algorithms
# Hard (30.94%)
# Total Accepted:    171.7K
# Total Submissions: 553.2K
# Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
#
# Given a set of non-overlapping intervals, insert a new interval into the
# intervals (merge if necessary).
#
# You may assume that the intervals were initially sorted according to their
# start times.
#
# Example 1:
#
#
# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]
#
#
# Example 2:
#
#
# Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# Output: [[1,2],[3,10],[12,16]]
# Explanation: Because the new interval [4,8] overlaps with
# [3,5],[6,7],[8,10].
#
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
#
# 考虑到原有的区间是排序的，所以只需要考虑插入的位置，并插入
class Solution:
    def insert(self, intervals, newInterval):
        idx = len(intervals)  # 注意为空的情况
        for i in range(len(intervals)):
            if newInterval[0] < intervals[i][0]:
                idx = i
                break
        intervals.insert(idx, newInterval)
        ret = []
        for item in intervals:
            if ret == [] or item[0] > ret[-1][1]:
                ret.append(item)
            else:
                ret[-1][1] = max(ret[-1][1], item[1])
        return ret


s = Solution()
ret = s.insert([[1, 3], [6, 9]], [2, 5])
print(ret)
