/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.72%)
 * Likes:    585
 * Dislikes: 0
 * Total Accepted:    88.4K
 * Total Submissions: 262K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// #include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if (strs.empty())
            return ret;
        string shorts = strs[0];
        for (string& s : strs) {
            if (s.size() < shorts.size())
                shorts = s;
        }
        // vector<int> sizes(n);
        // for (int i = 0; i < n; i++)
        //     sizes[i] = strs[i].size();
        // min_size = *min_element(sizes.begin(), sizes.end());
        for (int l = 0; l < shorts.size(); l++) {
            for (string& s : strs) {
                // 这里应当从头开始，因为字符串向量的长度可能为1
                if (shorts[l] != s[l])
                    return ret;
            }
            ret += shorts[l];
        }
        return ret;
    }
};

