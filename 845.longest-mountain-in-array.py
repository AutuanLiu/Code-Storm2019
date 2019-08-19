#
# @lc app=leetcode id=845 lang=python3
#
# [845] Longest Mountain in Array
#
# https://leetcode.com/problems/longest-mountain-in-array/description/
#
# algorithms
# Medium (33.89%)
# Total Accepted:    15.1K
# Total Submissions: 44.6K
# Testcase Example:  '[2,1,4,7,3,2,5]'
#
# Let's call any (contiguous) subarray B (of A) a mountain if the following
# properties hold:
#
#
# B.length >= 3
# There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] <
# B[i] > B[i+1] > ... > B[B.length - 1]
#
#
# (Note that B could be any subarray of A, including the entire array A.)
#
# Given an array A of integers, return the length of the longest mountain.
#
# Return 0 if there is no mountain.
#
# Example 1:
#
#
# Input: [2,1,4,7,3,2,5]
# Output: 5
# Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
#
#
# Example 2:
#
#
# Input: [2,2,2]
# Output: 0
# Explanation: There is no mountain.
#
#
# Note:
#
#
# 0 <= A.length <= 10000
# 0 <= A[i] <= 10000
#
#
# Follow up:
#
#
# Can you solve it using only one pass?
# Can you solve it in O(1) space?
#
#
#
# 双指针法，分别找到左右山顶三个点
# 左右山顶三个点就可以确定一个山峰
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        N = len(A)    # 数组的长度
        ans = base = 0

        while base < N:
            # 遍历整个数组
            end = base    # 尾指针一开始的时候和首指针在一起
            # 首指针已经定位了山峰的左点
            # 现在确定山峰的右点，分别是左->peak, peak->右
            if end + 1 < N and A[end] < A[end + 1]:
                # left -> peak
                while end + 1 < N and A[end] < A[end + 1]:
                    end += 1

                # 找到 peak，end处
                if end + 1 < N and A[end] > A[end + 1]:
                    while end + 1 < N and A[end] > A[end + 1]:
                        end += 1
                    # 找到 right 关键点，确定了一个山峰
                    ans = max(ans, end - base + 1)
            # 确定下一个山峰的开始点，也有可能山峰一开始就是下坡
            # 为了让循环进行下去，我们求 max(end, base + 1)
            base = max(end, base + 1)
        return ans
