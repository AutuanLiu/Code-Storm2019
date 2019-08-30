/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (52.15%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 17.5K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 */

// 贪心算法
// class Solution {
// public:
//     int integerBreak(int n)
//     {
//         if (n == 2)
//             return 1;
//         if (n == 3)
//             return 2;
//         // 尽可能多的分 3
//         int times3 = n / 3, rest = n % 3, times2 = 0;

//         // 判断剩余数字的情况，如果剩余4应该分2,2 如果剩余 5 应该分3,2，其余情况全部分为3
//         if (rest == 1) {
//             times3--;
//             times2 = 2; // 由3,1变为2,2
//         } else if (rest == 2) {
//             times2 = 1; // 分为3,2即可
//         }

//         // 数值的乘积
//         int ret = (int)pow(2, times2) * (int)pow(3, times3);
//         return ret;
//     }
// };

// 动态规划
// 某段长度也可以不拆分
class Solution {
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 1);
        // 第一层遍历时为了得到不同长度的乘积
        // 第二层循环是为了拆分不同的位置、> i/ 2是是对称的，所以只考虑一半
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                // 对应 之前计算的数值、不拆分、拆分
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
