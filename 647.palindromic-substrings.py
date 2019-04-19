#
# @lc app=leetcode id=647 lang=python3
#
# [647] Palindromic Substrings
#
# https://leetcode.com/problems/palindromic-substrings/description/
#
# algorithms
# Medium (56.29%)
# Total Accepted:    92.3K
# Total Submissions: 163.4K
# Testcase Example:  '"abc"'
#
# Given a string, your task is to count how many palindromic substrings in this
# string.
#
# The substrings with different start indexes or end indexes are counted as
# different substrings even they consist of same characters.
#
# Example 1:
#
#
# Input: "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
#
#
#
#
# Example 2:
#
#
# Input: "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
#
#
#
#
# Note:
#
#
# The input string length won't exceed 1000.
#
#
#
# 认为空字符串也是一个回文串
#
class Solution:
    def countSubstrings(self, s: str) -> int:
        lens = len(s)
        if lens <= 1:
            return 1
        cnt = 0  # 用于统计
        dp = [False] * lens * lens
        # 先确定结束位置再确定开始位置 [i, j]
        for j in range(lens):
            dp[j * lens + j] = True  # 单个字符就是回文串
            for i in range(j):
                if i + 1 == j:
                    dp[i * lens + j] = s[i] == s[j]  # 相邻关系
                if i + 1 < j:
                    dp[i * lens + j] = (s[i] == s[j] and dp[(i + 1) * lens + j - 1])
        for item in dp:
            cnt = cnt + 1 if item else cnt
        return cnt
