/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.50%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 63.9K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 *
 * 示例 1:
 *
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 *
 *
 * 示例 2:
 *
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 *
 *
 */
// 动态规划
// 一半是从后往前分析（生成问题、路径问题）
// 以 “226” 为例，要想到达 226 有两种情况 从2加一个26或者从22加一个6
// 所以，用dp[i] 表示到达i处的解码方式，则有 dp[i] = dp[i - 1] + dp[i - 2]
// 所以到达i只和i-1,i-2有关系
// 如果 i 是 0，i-1是1,2 则i不可以单独构成一个编码，dp[i] = dp[i - 2]
// 如果 i 不是0，i-1是1, dp[i] = dp[i -1] +dp[i-2]
// 如果 i 不是0，i-1是2，i-2 <=6,dp[i] = dp[i -1] +dp[i-2]
class Solution {
public:
    int numDecodings(string s)
    {
        int ret = 0, n = s.length();
        if (s[0] == '0' || n == 0)
            return 0;
        int pre = 1, cur = 1;
        for (int i = 1; i < n; i++) {
            int tmp = cur;
            // 如果该位不为 '0' 说明该位单独成字母组合
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    cur = pre;
                else
                    return 0;
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                cur = cur + pre;
            }
            pre = tmp;
        }
        return cur;
    }
};

// 动态规划
// f[i] = f[i+1] + g(i, i+1)*f[i+2] 含义即一个字母可以由一位数编码也可以由两位数编码
// f[i] 表示从第i位开始的不同翻译的数目 上述为递归表达式
// 动态规划形式为 关键在于确定 g(i,i+1)是否在有效的范围内
//
class Solution {
public:
    int numDecodings(string s)
    {
        int ret = 0, n = s.length();
        if (s[0] == '0' || n == 0)
            return 0;
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            //如果该位不为'0'，说明该位单独成字母合法
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            //如果后两位能组成"1x"（x为任意数字）或者"2x"（x小于7），说明最后两位组成字母合法
            if ((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] <= '6'))
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (s.empty() || s[0] == '0')
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
