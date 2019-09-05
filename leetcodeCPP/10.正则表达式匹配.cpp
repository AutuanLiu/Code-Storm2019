
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.01%)
 * Likes:    560
 * Dislikes: 0
 * Total Accepted:    22.7K
 * Total Submissions: 94.6K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */

class Solution {
public:
    bool isMatch(string s, string p)
    {
        // 模式是空 考虑字符串是否是空
        if (p.empty())
            return s.empty();
        // 模式长度大于1最少为2的时候，如果p[1]是 *
        if (p.length() > 1 && p[1] == '*')
            // * 不匹配内容或者（匹配一个字符并且匹配多个）
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
};


// !动态规划
// 1.状态bool型数组 ， dp[i][j] 表示s[0 - i] 与p[0 - j] 是否匹配
// 2.分情况三种
//  1. if p[j] == s[i] : dp[i][j] = dp[i - 1][j - 1] #当前已经匹配，最终结果取决于之前是否匹配
//  2. if p[j] == '.' : dp[i][j] = dp[i - 1][j - 1] #'.' 代表任意，则必然匹配，最终结果取决于之前是否匹配
//  3. if p[j] == '*' : #判断 '*' 前面的模式
//      1. if p[j - 1] != s[i] and p[j - 1] != '.' : dp[i][j] = dp[i][j - 2]
//      2. if p[j - 1] == s[i] or p[j - 1] == '.':
//          dp[i][j] = dp[i][j - 1] # * 代表单个字符
//          dp[i][j] = dp[i - 1][j] # * 代表多个字符
//          dp[i][j] = dp[i][j - 2] # * 代表0个字符

// class Solution {
// public:
//     bool isMatch(string s, string p)
//     {
//         int m = s.length(), n = p.length();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         dp[0][0] = 1;
//         for (int i = 0; i < n; i++) {
//             if (p[i] == '*' && dp[0][i - 1])
//                 dp[0][i + 1] = 1;
//         }
//         for (int i = 0; i < m; ++i) {
//             for (int j = 1; j < n; ++j) {
//                 if (p[j] == s[i] || p[j] == '.')
//                     dp[i + 1][j + 1] = dp[i][j];
//                 if (p[j] == '*') {
//                     if (j > 0 && p[j - 1] != s[i] && p[j - 1] != '.')
//                         dp[i + 1][j + 1] = dp[i + 1][j - 1];
//                     else
//                         dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1];
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

// 动态规划2
// class Solution {
// public:
//     bool isMatch(string s, string p)
//     {
//         int m = s.length(), n = p.length();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         dp[0][0] = 1;
//         for (int i = 0; i <= m; ++i) {
//             for (int j = 1; j <= n; ++j) {
//                 // 首先要保证 p[j-1]是存在的也即j>1
//                 if (j > 1 && p[j - 1] == '*') {
//                     if (i > 0)
//                         dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.') ? 1 : 0;
//                     dp[i][j] = dp[i][j] || dp[i][j - 2] ? 1 : 0;
//                 } else if (i > 0) {
//                     dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.') ? 1 : 0;
//                 }
//             }
//         }
//         return dp[m][n] == 1;
//     }
// };
