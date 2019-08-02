/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (38.35%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    68.4K
 * Total Submissions: 176.8K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
// 暴力法
// class Solution {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if (needle == "")
//             return 0;
//         int m = haystack.length(), n = needle.length();
//         for (int it = 0; it < m - n + 1; it++) {
//             if (haystack.substr(it, n) == needle)
//                 return it;
//         }
//         return -1;
//     }
// };

// 使用库函数 find
// class Solution {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if (needle.empty())
//             return 0;
//         return haystack.find(needle);
//     }
// };

// KMP 算法 https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
// https://www.zhihu.com/question/21923021
// KMP 算法的复杂度是 O(n), n 为被匹配文本的长度
// 匹配失败时，总是能够让 pattern 回退到某个位置，使 text 不用回退
class Solution {
public:
    // 自身匹配的过程，用 pattern 的后缀匹配前缀
    // 前缀 索引从0到n-1， 后缀 索引从1到n-1
    // 用后缀匹配前缀 是因为 maxMatch 数组要按照顺序生成
    vector<int> maxMatch(string needle)
    {
        int n = needle.length();
        vector<int> next(n);
        for (int it = 1, cnt = 0; it < n; it++) {
            // 当匹配的最大长度大于 0 并且
            while (cnt > 0 && needle[cnt] != needle[it]) {
                cnt = next[cnt - 1];
            }

            if (needle[it] == needle[cnt])
                cnt++;

            // 赋值， cnt 可能为 0
            next[it] = cnt;
        }
        return next;
    }

    // 两个字符串之间的匹配
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        vector<int> maxLengths = maxMatch(needle);
        int m = haystack.size(), n = needle.size();
        for (int it = 0, cnt = 0; it < m; it++) {
            while (cnt > 0 && haystack[it] != needle[cnt]) {
                cnt = maxLengths[cnt - 1];
            }

            if (haystack[it] == needle[cnt])
                cnt++;

            // 计数完成后，判断是否和pattern的长度相等，如果相等，那么返回起始位置的坐标
            if (cnt == n)
                return it - n + 1;
        }
        return -1;
    }
};
