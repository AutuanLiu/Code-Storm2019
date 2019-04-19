#
# @lc app=leetcode id=516 lang=python3
#
# [516] Longest Palindromic Subsequence
#
# https://leetcode.com/problems/longest-palindromic-subsequence/description/
#
# algorithms
# Medium (45.83%)
# Total Accepted:    56.3K
# Total Submissions: 122.2K
# Testcase Example:  '"bbbab"'
#
#
# Given a string s, find the longest palindromic subsequence's length in s. You
# may assume that the maximum length of s is 1000.
#
#
# Example 1:
# Input:
#
# "bbbab"
#
# Output:
#
# 4
#
# One possible longest palindromic subsequence is "bbbb".
#
#
# Example 2:
# Input:
#
# "cbbd"
#
# Output:
#
# 2
#
# One possible longest palindromic subsequence is "bb".
# 遇到一个数组，如果求其最大、最小、最长、最短的个数，而不需要知道具体解的问题，一般考虑动态规划
#
# 当已知一个序列是回文时，添加首尾元素后的序列存在两种情况，一种是首尾元素相等，则最长回文的长度加2，
# 当首尾元素不相等，则最长回文序列为仅添加首元素时的最长回文与仅添加尾元素时的最长回文之间的最大值。
# 我们可以用dp[i][j]表示s[i…j]中的最长回文序列，而状态转移方程则是

# 1. i > j，dp[i][j] = 0；
# 2. i == j，dp[i][j] = 1；
# 3. i < j且s[i] == s[j]，dp[i][j] = dp[i + 1][j - 1] + 2；
# 4. i < j且s[i]！= s[j]，dp[i][j] = max(dp[i + 1][j]，dp[i][j - 1])；

# 从状态转移方程可以看出，计算dp[i][j]时需要用到dp[i+1][j - 1]和dp[i + 1][j]，要使用 i + 1,
# 所以对于i的遍历应该从尾部开始，
# 最后返回dp[0][s.length() - 1]就行
#
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        lens = len(s)
        if lens <= 1:
            return 1
        dp = [0] * lens * lens  # 应当初始化为 0 因为 i < j 恒成立
        for i in range(lens -1, -1, -1):
            dp[i * lens + i] = 1  # 一个元素肯定是回文串, 需要从后往前访问
            for j in range(i + 1, lens):
                if s[i] == s[j]:
                    dp[i * lens + j] = dp[(i + 1) * lens + j - 1] + 2
                elif s[i] != s[j]:
                    dp[i * lens + j] = max(dp[(i + 1) * lens + j], dp[i * lens + j - 1])
        return dp[lens - 1]

s = Solution()
print(s.longestPalindromeSubseq('cbbd'))
