#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#
# algorithms
# Medium (40.87%)
# Total Accepted:    374.1K
# Total Submissions: 909.2K
# Testcase Example:  '"23"'
#
# Given a string containing digits from 2-9 inclusive, return all possible
# letter combinations that the number could represent.
#
# A mapping of digit to letters (just like on the telephone buttons) is given
# below. Note that 1 does not map to any letters.
#
#
#
# Example:
#
#
# Input: "23"
# ret: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
#
#
# Note:
#
# Although the above answer is in lexicographical order, your answer could be
# in any order you want.
#
# 回溯法
#
class Solution:
    def letterCombinations(self, digits: str):
        phone = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

        def backtrack(combination, digits):
            # 如果到达数字的结尾，那么当前路径就是一个可行路径
            if len(digits) == 0:
                ret.append(combination)
            else:
                # 如果没有到达结尾，那么就遍历当前路径（节点）下所有可能的数值
                # 继续访问剩下的数字，是一个递归过程
                for letter in phone[digits[0]]:
                    backtrack(combination + letter, digits[1:])

        ret = []
        if digits:
            backtrack("", digits)
        return ret

s = Solution()
ret = s.letterCombinations('2348')
print(ret)
