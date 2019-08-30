#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// 贪心法
int cut_greedy(int length)
{
    if (length < 2) // 不可以剪
        return 0;
    if (length == 2) // 两个 1
        return 1;
    if (length == 3) // 一个 2 一个 1
        return 2;
    // 那么绳子的最小单位为 1, 2, 3, 当剪3的时候可以获得最大的乘积
    // 所以我们应当考虑尽可能多的剪成 3，如果最后剩 4 那么应该剪两个2而不是一个3一个1
    int times3 = length / 3, times2 = 0;
    // 判断最后剩下的数字
    // 判断剪成2的个数
    if (length % 3 == 1) {
        times3--; // 说明最后剩下的是4应该剪两个2
        times2 = 2;
    } else if (length % 3 == 2) {
        // 最后剩下了5
        times2 = 1;
    }

    // 数据类型转换 pow 的返回类型为 double
    int ret = (int)pow(3, times3) * (int)pow(2, times2);
    return ret;
}

// 动态规划
int cut_dp(int length)
{
    int* dp = new int[length + 1];
    dp[1] = 1;
    int ret = 0;
    for (int i = 2; i <= length; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], max(j * (i - j), dp[j] * dp[i - j]));
        }
    }
    ret = dp[length];
    if (dp != nullptr)
        delete[] dp;
    return ret;
}

int main(void)
{
    // 你可以假设 n 不小于 2 且不大于 58
    int nums[] = { 6, 23, 50, 45, 18 };
    for (int& i : nums) {
        cout << cut_greedy(i) << endl;
        cout << cut_dp(i) << endl;
    }
    return 0;
}