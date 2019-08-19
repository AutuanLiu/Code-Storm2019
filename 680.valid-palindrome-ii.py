#
# @lc app=leetcode id=680 lang=python3
#
# [680] Valid Palindrome II
#
# https://leetcode.com/problems/valid-palindrome-ii/description/
#
# algorithms
# Easy (33.89%)
# Total Accepted:    69.4K
# Total Submissions: 203.9K
# Testcase Example:  '"aba"'
#
#
# Given a non-empty string s, you may delete at most one character.  Judge
# whether you can make it a palindrome.
#
#
# Example 1:
#
# Input: "aba"
# Output: True
#
#
#
# Example 2:
#
# Input: "abca"
# Output: True
# Explanation: You could delete the character 'c'.
#
#
#
# Note:
#
# The string will only contain lowercase characters a-z.
# The maximum length of the string is 50000.
#
#
# TLE
# class Solution:
#     def validPalindrome(self, s: str) -> bool:
#         if self.isPalindrome(s):
#             return True
#         ret = False
#         for i in range(len(s)):
#             new_s = s[:i] + s[(i + 1):]
#             if self.isPalindrome(new_s):
#                 ret = True
#                 break
#         return ret

#     def isPalindrome(self, s):
#         return s == s[::-1]

# class Solution:
#     def validPalindrome(self, s: str) -> bool:
#         if self.isPalindrome(s):
#             return True
#         low, high = 0, len(s) - 1
#         strPart = lambda s, x: s[:x] + s[x + 1:]
#         while low < high:
#             if s[low] != s[high]:
#                 return self.isPalindrome(strPart(s, low)) or self.isPalindrome(strPart(s, high))
#             low += 1
#             high -= 1
#         return True

#     def isPalindrome(self, s):
#         return s == s[::-1]


class Solution:
    def validPalindrome(self, s: str) -> bool:
        def is_pali_range(i, j):
            return all(s[k] == s[j - k + i] for k in range(i, j))

        for i in range(len(s) // 2):
            if s[i] != s[~i]:
                j = len(s) - 1 - i
                return is_pali_range(i + 1, j) or is_pali_range(i, j - 1)
        return True
