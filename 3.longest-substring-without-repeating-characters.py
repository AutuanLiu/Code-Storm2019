#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (28.13%)
# Total Accepted:    856.6K
# Total Submissions: 3M
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
#
#
# Example 1:
#
#
# Input: "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.
#
#
#
# Example 2:
#
#
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
#
#
#
# Example 3:
#
#
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3.
# ⁠            Note that the answer must be a substring, "pwke" is a
# subsequence and not a substring.
#
#
# array/string 问题通常使用滑动窗的方法
# [i, j) i,j 表示左右边界
# 滑动窗有左边界和右边界，刚开始时左右边界都在 0 处
# 如果右边界处的值已经在集合中，则删除左边界处的值，左边界滑动1，否则把右边界的值加入集合，并求当前的窗口长度 j - i, 继续判断下一个值
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) < 1:
            return 0
        lens = len(s)
        res, lb, rb, hash_set = 0, 0, 0, set()
        while lb < lens and rb < lens:
            if s[rb] not in hash_set:
                hash_set.add(s[rb])
                rb += 1
                res = max(res, rb - lb)
            else:
                hash_set.remove(s[lb])
                lb += 1
        return res


if __name__ == '__main__':
    s = Solution()
    res = s.lengthOfLongestSubstring('')
    print(res)
    res = s.lengthOfLongestSubstring('abcabcbb')
    print(res)
    res = s.lengthOfLongestSubstring('bbbbb')
    print(res)
    res = s.lengthOfLongestSubstring('pwwkew')
    print(res)
