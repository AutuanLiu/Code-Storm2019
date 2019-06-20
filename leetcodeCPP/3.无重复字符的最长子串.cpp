/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.94%)
 * Likes:    1931
 * Dislikes: 0
 * Total Accepted:    139.4K
 * Total Submissions: 465.5K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 */
// 滑动窗口(双指针)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, start = 0, end = 0;
        unordered_set<char> sub_set;
        while (start < s.size() && end < s.size() && start <= end) {
            if (sub_set.find(s[end]) == sub_set.end()) {
                sub_set.insert(s[end]);
                end += 1;
                ret = max(ret, end - start);
            } else {
                sub_set.erase(s[start]);
                start += 1;
            }
        }
        return ret;
    }
};
