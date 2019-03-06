class Solution
{
  public:
    int jumpFloorII(int number)
    {
        if (number < 2)
            return number;
        int total = 1;
        for (int i = 1; i < number; i++)
            total *= 2;
        return total;
    }
};

// 数学归纳法
class Solution
{
  public:
    int jumpFloorII(int number)
    {
        return number == 0 ? 0 : pow(2, number - 1);
    }
};
