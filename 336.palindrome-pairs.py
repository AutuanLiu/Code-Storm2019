#
# @lc app=leetcode id=336 lang=python3
#
# [336] Palindrome Pairs
#
# https://leetcode.com/problems/palindrome-pairs/description/
#
# algorithms
# Hard (30.48%)
# Total Accepted:    66K
# Total Submissions: 215.7K
# Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
#
# Given a list of unique words, find all pairs of distinct indices (i, j) in
# the given list, so that the concatenation of the two words, i.e. words[i] +
# words[j] is a palindrome.
#
# Example 1:
#
#
#
# Input: ["abcd","dcba","lls","s","sssll"]
# Output: [[0,1],[1,0],[3,2],[2,4]]
# Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
#
#
#
# Example 2:
#
#
# Input: ["bat","tab","cat"]
# Output: [[0,1],[1,0]]
# Explanation: The palindromes are ["battab","tabbat"]
#
#
#
#
# 暴力法超时
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        ret, lens = [], len(words)
        if lens <= 1:
            return ret
        for i in range(lens):
            for j in range(lens):
                if i != j and self.isPalindrome(words[i] + words[j]):
                    ret.append([i, j])
        return ret

    def isPalindrome(self, s):
        return s == s[-1::-1]

# 利用字典保存单词 -> 下标的键值对 {单词：下标}
# 遍历单词列表words，记当前单词为word，下标为idx：
# 1). 若当前单词word(idx)本身为回文，且words中存在空串(idx1)，则将[idx1, idx], [idx, idx1]加入答案
# 2). 若当前单词的逆序串(idx1)在words中，则将[idx, idx1], [idx1, idx]加入答案
# 3). 将当前单词word拆分为左右两半left，right。
#      3.1) 若left为回文，并且right的逆序串(idx1)在words中，则将[idx1, idx]加入答案
#      3.2) 若right为回文，并且left的逆序串(idx1)在words中，则将[idx, idx1]加入答案

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        # 构造单词字典 unique words 是一个很重要的条件
        # 为保证结果不存在重复元素，使用集合进行存储
        ret, dicts = set(), {word: idx for idx, word in enumerate(words)}
        for idx, word in enumerate(words):
            if word != "" and self.isPalindrome(word) and "" in dicts.keys():
                ret.add((idx, dicts[""]))  # set 不支持 list
                ret.add((dicts[""], idx))

            # 逆序在单词表中，并且 两个序号不应该相等
            rword = word[::-1]
            if rword in dicts.keys():
                if dicts[rword] != idx:
                    ret.add((idx, dicts[rword]))
                    ret.add((dicts[rword], idx))

            # 拆分为两部分
            # 左右最少包含一个字母
            for t in range(1, len(word)):
                left, right = word[:t], word[t:]
                rleft, rright = left[::-1], right[::-1]
                if self.isPalindrome(left) and rright in dicts.keys():
                    ret.add((dicts[rright], idx))
                if self.isPalindrome(right) and rleft in dicts.keys():
                    ret.add((idx, dicts[rleft]))

        return list(map(list, ret))

    def isPalindrome(self, s):
        return s == s[-1::-1]
