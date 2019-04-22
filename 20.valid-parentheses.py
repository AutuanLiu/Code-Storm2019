#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#
# https://leetcode.com/problems/valid-parentheses/description/
#
# algorithms
# Easy (36.08%)
# Total Accepted:    564.1K
# Total Submissions: 1.6M
# Testcase Example:  '"()"'
#
# Given a string containing just the characters '(', ')', '{', '}', '[' and
# ']', determine if the input string is valid.
# 
# An input string is valid if:
# 
# 
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# 
# 
# Note that an empty string is also considered valid.
# 
# Example 1:
# 
# 
# Input: "()"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: "()[]{}"
# Output: true
# 
# 
# Example 3:
# 
# 
# Input: "(]"
# Output: false
# 
# 
# Example 4:
# 
# 
# Input: "([)]"
# Output: false
# 
# 
# Example 5:
# 
# 
# Input: "{[]}"
# Output: true
# 
# 
#
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        # if s == '':
        #     return True
        hash = {')': '(', ']': '[', '}': '{'}
        left, right = ('(', '[', '{'), (')', ']', '}')
        for item in s:
            if item in left:
                stack.append(item)
            elif item in right:
                if stack != [] and stack[-1] == hash[item]:
                    stack.pop()
                else:
                    return False
        return stack == []

s = Solution()
# ret = s.isValid('{[]}')
ret = s.isValid('')
# ret = s.isValid('{[}')
# ret = s.isValid('{[]')
print(ret)    

