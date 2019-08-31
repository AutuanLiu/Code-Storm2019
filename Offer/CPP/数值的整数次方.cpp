// 数值的整数次方
// 快速求幂
class Solution {
public:
    double Power(double base, int exponent)
    {
        long long p = abs((long long)exponent);
        double ret = 1.0;
        while (p) {
            if (p & 1)
                ret *= base;
            base *= base;
            p >>= 1;
        }
        return (exponent > 0) ? ret : 1 / ret;
    }
};

// 二分法求幂
// 位运算比取模和除法运算要快很多
// 递归
class Solution {
public:
    double Power(double base, int exponent)
    {
        if (exponent > 0) {
            if (exponent == 1)
                return base;
            if (exponent & 1) // 奇数
                return Power(base, exponent >> 1) * Power(base, exponent >> 1) * base;
            else
                return Power(base, exponent >> 1) * Power(base, exponent >> 1);
        } else if (exponent == 0)
            return 1;
        else
            return 1 / Power(base, 0 - exponent);
    }
};
