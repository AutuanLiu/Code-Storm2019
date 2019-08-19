/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (66.05%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 33.7K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */
// 以空格或者字符串结束符 '\0'划分单词，对单个单词进行翻转
class Solution {
public:
    string reverseWords(string s)
    {
        string ret = "", tmp = "";
        int n = s.length(); // s.length() 默认不包含最后的结束符，这里索引要加 1
        for (int i = 0; i <= n; i++) {
            if (s[i] == ' ' || s[i] == '\0') {
                reverse(tmp.begin(), tmp.end());
                ret = ret + tmp + s[i];
                tmp = "";
            } else {
                tmp += s[i];
            }
        }
        return ret;
    }
};
