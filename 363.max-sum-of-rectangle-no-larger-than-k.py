#
# @lc app=leetcode id=363 lang=python3
#
# [363] Max Sum of Rectangle No Larger Than K
#
# https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
#
# algorithms
# Hard (34.86%)
# Total Accepted:    26.5K
# Total Submissions: 75.9K
# Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
#
# Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
# rectangle in the matrix such that its sum is no larger than k.
# 
# Example:
# 
# 
# Input: matrix = [[1,0,1],[0,-2,3]], k = 2
# Output: 2 
# Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is
# 2,
# and 2 is the max number no larger than k (k = 2).
# 
# Note:
# 
# 
# The rectangle inside the matrix must have an area > 0.
# What if the number of rows is much larger than the number of columns?
# 
#
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        

