class Solution
{
  public:
    int jumpFloorII(int number)
    {
        if (number == 0)
            return number;
        int total = 1;
        for (int i = 1; i < number; i++)
            total *= 2;
        return total;
    }
};

class Solution
{
  public:
    int jumpFloorII(int number)
    {
        if (number == 0)
            return 0;
        int total = 1;
        if (number == 1)
            return 1;
        for (int i = 1; i < number; i++)
        {
            total *= 2;
        }
        return total;
    }
};

class Solution
{
  public:
    int jumpFloorII(int number)
    {
        int solution, s1 = 1, i;
        if (number <= 0)
            return 0;
        else if (number == 1)
            return 1;
        else
        {
            for (i = 2; i <= number; i++)
            {
                solution = 2 * s1;
                s1 = solution;
            }
            return solution;
        }
    }
};
