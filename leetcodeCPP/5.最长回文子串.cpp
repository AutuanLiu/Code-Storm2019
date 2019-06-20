/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.47%)
 * Likes:    951
 * Dislikes: 0
 * Total Accepted:    67.1K
 * Total Submissions: 263.6K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 *
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 */
// class Solution
// {
// public:
//     string longestPalindrome(string s){
//         string ret;
//         int start = 0, len = s.size(), maxlen = 1;
//         if (len <= 1)
//             return s;
//         vector<vector<bool>> dp(len, vector<bool>(len));
//         for (int j = 0; j < len; j++){
//             dp[j][j] = true;
//             for (int i = 0; i < j; i++){
//                 if (i == j - 1)
//                     dp[i][j] = (s[i] == s[j]);
//                 if (i < j - 1)
//                     dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
//                 if (dp[i][j] && j - i + 1 > maxlen){
//                     start = i;
//                     maxlen = j - i + 1;
//                 }
//             }
//         }
//         return s.substr(start, maxlen);
//     }
// };

// 方法二：考虑是否可以回缩，即 i+1,j-1 是否构成自区间
// dp[i, j] = (s[i] == s[j]) && (j-i<2 || dp[i+1, j-1])
// 即考虑两种情况 1.不构成区间，s[i] == s[j] && j-i<2
//              2. 构成区间，s[i] == s[j] && dp[i+1, j-1]
class Solution
{
public:
    string longestPalindrome(string s){
        int len = s.size(), maxlen = 1, start = 0;
        if (len <= 1)
            return s;
        vector<vector<bool>> dp(len, vector<bool>(len));
        for (int j = 0; j < len; j++) {
            dp[j][j] = true;
            for (int i = 0; i < j; i++) {
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
                // 考虑是否更新最大长度
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
