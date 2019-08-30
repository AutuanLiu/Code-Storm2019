// 二进制中1的个数.cpp
// 减法运算
class Solution {
public:
    int NumberOf1(int n)
    {
        int cnt = 0;
        while (n) {
            cnt++;
            n = (n - 1) & n;
        }
        return cnt;
    }
};

class Solution {
public:
    int NumberOf1(int n)
    {
        int cnt = 0;
        if (n < 0)
            n = n & 0xffffffff; // 补码
        while (n) {
            cnt++;
            n = (n - 1) & n;
        }
        return cnt;
    }
};
