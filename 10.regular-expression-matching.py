#
# @lc app=leetcode id=10 lang=python3
#
# [10] Regular Expression Matching
#
# https://leetcode.com/problems/regular-expression-matching/description/
#
# algorithms
# Hard (25.03%)
# Total Accepted:    287.3K
# Total Submissions: 1.1M
# Testcase Example:  '"aa"\n"a"'
#
# Given an input string (s) and a pattern (p), implement regular expression
# matching with support for '.' and '*'.
#
#
# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.
#
#
# The matching should cover the entire input string (not partial).
#
# Note:
#
#
# s could be empty and contains only lowercase letters a-z.
# p could be empty and contains only lowercase letters a-z, and characters like
# . or *.
#
#
# Example 1:
#
#
# Input:
# s = "aa"
# p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
#
#
# Example 2:
#
#
# Input:
# s = "aa"
# p = "a*"
# Output: true
# Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore,
# by repeating 'a' once, it becomes "aa".
#
#
# Example 3:
#
#
# Input:
# s = "ab"
# p = ".*"
# Output: true
# Explanation: ".*" means "zero or more (*) of any character (.)".
#
#
# Example 4:
#
#
# Input:
# s = "aab"
# p = "c*a*b"
# Output: true
# Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
# it matches "aab".
#
#
# Example 5:
#
#
# Input:
# s = "mississippi"
# p = "mis*is*p*."
# Output: false
#
# https://www.youtube.com/watch?v=c5vsle60Uw8
#
#
# !动态规划
# 1.状态bool型数组 ， dp[i][j]表示s[0 - i]与p[0 - j]是否匹配
# 2.分情况三种
#     1. if p[j] == s[i]: dp[i][j] = dp[i - 1][j - 1]  # 当前已经匹配，最终结果取决于之前是否匹配
#     2. if p[j] == '.': dp[i][j] = dp[i - 1][j - 1]  # '.' 代表任意，则必然匹配，最终结果取决于之前是否匹配
#     3. if p[j] == '*':  # 判断 '*' 前面的模式
#         1. if p[j - 1] != s[i] and p[j - 1] != '.': dp[i][j] = dp[i][j - 2]
#         2. if p[j - 1] == s[i] or p[j - 1] == '.':
#             dp[i][j] = dp[i][j - 1] # * 代表单个字符
#             dp[i][j] = dp[i - 1][j] # * 代表多个字符
#             dp[i][j] = dp[i][j - 2] # * 代表0个字符
#
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # s = '', p ='.*' 返回 true
        # s = '', p ='' 返回 true
        dp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]
        # 初始化并预处理
        dp[0][0] = True
        # s = 'aab', p='c*aab'
        for i in range(len(p)):
            if p[i] == '*' and dp[0][i - 1]:
                dp[0][i + 1] = True

        for i in range(len(s)):
            for j in range(len(p)):
                if p[j] == s[i] or p[j] == '.':
                    dp[i + 1][j + 1] = dp[i][j]
                if p[j] == '*':
                    if p[j - 1] != s[i] and p[j - 1] != '.':
                        dp[i + 1][j + 1] = dp[i + 1][j - 1]
                    else:
                        dp[i + 1][j + 1] = dp[i + 1][j] or dp[i][j + 1] or dp[i + 1][j - 1]

        return dp[len(s)][len(p)]

s = Solution()
res = s.isMatch('aa', 'a')
print(res)
res = s.isMatch('', '.*')
print(res)
res = s.isMatch('', '')
print(res)
