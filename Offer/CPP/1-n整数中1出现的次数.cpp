// 1-n整数中1出现的次数.cpp
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ret = 0;
        if (n < 1)
            return 0;
        for (int i = 1; i <= n; ++i) {
            int temp = i;
            while (temp) {
                if (temp % 10 == 1)
                    ++ret;
                temp /= 10;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ret = 0;
        for (int i = 1; i <= n; i *= 10) {
            int a = n / i, b = n % i;
            ret += (a + 8) / 10 * i + (a % 10 == 1 ? 1 : 0) * (b + 1);
        }
        return ret;
    }
};
