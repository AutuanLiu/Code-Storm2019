// 快速求幂
class Solution
{
  public:
    double Power(double base, int exponent)
    {
        long long p = abs((long long)exponent);
        double r = 1.0;
        while (p)
        {
            if (p & 1)
                r *= base;
            base *= base;
            p >>= 1;
        }
        return (exponent > 0) ? r : 1 / r;
    }
};

// 二分法求幂
class Solution
{
  public:
    double Power(double base, int exponent)
    {
        if (exponent > 0)
        {
            if (exponent == 1)
                return base;
            if (exponent & 1)
                return Power(base, exponent >> 1) * Power(base, exponent >> 1) * base;
            else
                return Power(base, exponent >> 1) * Power(base, exponent >> 1);
        }
        else if (exponent == 0)
            return 1;
        else
            return 1 / Power(base, 0 - exponent);
    }
};
