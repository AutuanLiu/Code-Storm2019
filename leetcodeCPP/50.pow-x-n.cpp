/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (32.88%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 64.8K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */
// 快速幂递归
// class Solution {
// public:
//     double myPow(double x, int n)
//     {
//         long long N = n;
//         if (N < 0) {
//             x = 1 / x;
//             N = -N;
//         }
//         return fastPow(x, N);
//     }

//     double fastPow(double x, long n)
//     {
//         if (n == 0)
//             return 1.0;
//         double half = fastPow(x, n / 2);
//         return n % 2 == 0 ? half * half : half * half * x;
//     }
// };

// 快速幂循环
class Solution {
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ret = 1, cur = x;
        for (long long it = N; it != 0; it /= 2) {
            // 如果是奇数的话，就乘上一个 当前值，否则就是当前值乘上一个当前值
            if (it % 2 == 1)
                ret = cur * ret;
            cur = cur * cur;
        }
        return ret;
    }
};
