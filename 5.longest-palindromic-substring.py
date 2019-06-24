#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#
# https://leetcode.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (26.88%)
# Total Accepted:    510.6K
# Total Submissions: 1.9M
# Testcase Example:  '"babad"'
#
# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000.
#
# Example 1:
#
#
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
#
#
# Example 2:
#
#
# Input: "cbbd"
# Output: "bb"
#
# https://blog.csdn.net/u013309870/article/details/70742315
#
# 回文串问题
#
#
class Solution:
    def longestPalindrome(self, s: str) -> str:
        lens = len(s)
        if lens <= 1:
            return s
        start, max_len = 0, 1  # 这里注意最短的回文串为一个字符
        dp = [False] * lens * lens
        # j表示结束的位置，最小为 1，如果为0则和i重合，返回 s
        # 从 i 开始到 j 结束
        for j in range(lens):
            dp[j * lens + j] = True  # 一个元素肯定是回文串
            for i in range(j):
        # for i in range(lens - 1, -1, -1):
        #     dp[i * lens + i] = True
        #     for j in range(i + 1, lens):
                if i == j - 1:
                    # 如果s[j]==s[i]当串的长度小于等于2时，肯定是回文子串，如 1，1，就是回文串
                    dp[i * lens + j] = s[i] == s[j]
                if i < j - 1:
                    dp[i * lens + j] = (s[i] == s[j]) and dp[(i + 1) * lens + j - 1]
                    # 如果长度大于2时，则需要判断dp[i+1][j-1]是不是回文
                if dp[i * lens + j] and j - i + 1 > max_len:
                    start, max_len = i, j - i + 1
        ret = s[start:(start + max_len)]
        return ret

# s = Solution()
# res = s.longestPalindrome('c')
# print(res)

# round 2
# 问题的关键在确定最长回文串的起始和终止位置

class Solution:
    def longestPalindrome(self, s: str) -> str:
        pass
