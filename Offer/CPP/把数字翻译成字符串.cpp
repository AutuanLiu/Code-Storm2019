// 把数字翻译成字符串.cpp
// leetcode 91 解码方法
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// 动态规划，从右到左计算。
// f(r-2) = f(r-1)+g(r-2,r-1)*f(r);
// 如果r-2，r-1能够翻译成字符，则g(r-2,r-1)=1，否则为0
// 动态规划
// f[i] = f[i+1] + g(i, i+1)*f[i+2] 含义即一个字母可以由一位数编码也可以由两位数编码
// f[i] 表示从第i位开始的不同翻译的数目

// 从后往前
int decode(string s)
{
    int f1 = 0, f2 = 1, g = 0, ret, n = s.length();
    for (int i = n - 2; i >= 0; i--) {
        if ((s[i] == '1') || (s[i] == '2' && s[i + 1] < '6'))
            g = 1;
        else
            g = 0;
        ret = f2 + g * f1;
        f1 = f2;
        f2 = ret;
    }
    return ret;
}

// 从前往后
int decode1(string s)
{
    int f1 = 1, f2 = 1, g = 0, ret, n = s.length();
    for (int i = 1; i < n; i++) {
        if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] < '6'))
            g = 1;
        else
            g = 0;
        ret = f2 + g * f1;
        f1 = f2;
        f2 = ret;
    }
    return ret;
}

int getTranslationCount(int number)
{
    if (number < 0)
        return 0;
    if (number == 1)
        return 1;
    /*return decode(to_string(number));*/
    return decode1(to_string(number));
}

int main(void)
{
    cout << getTranslationCount(-10) << endl; // 0
    cout << getTranslationCount(1234) << endl; // 3
    cout << getTranslationCount(12258) << endl; // 5
    return 0;
}
