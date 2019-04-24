#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (33.18%)
# Total Accepted:    445.6K
# Total Submissions: 1.3M
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
#
# If there is no common prefix, return an empty string "".
#
# Example 1:
#
#
# Input: ["flower","flow","flight"]
# Output: "fl"
#
#
# Example 2:
#
#
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
#
#
# Note:
#
# All given inputs are in lowercase letters a-z.
#
#
class Solution:
    def longestCommonPrefix(self, strs) -> str:
        ret, n, lens = '', len(strs), [len(item) for item in strs]
        if n == 0:
            return ret
        min_x = min(lens)

        while min_x:
            t, tmp = 1, strs[0][: min_x]
            for i in range(1, n):
                if strs[i][: min_x] != tmp:
                    min_x -= 1
                    break
                else:
                    t += 1
            if t == n:
                ret = tmp
                break

        return ret

s = Solution()
ret = s.longestCommonPrefix(['aa', 'ab'])
print(ret)
