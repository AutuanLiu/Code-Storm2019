class Solution
{
  public:
    int jumpFloor(int n)
    {
        int f = 1, g = 2;
        n--;
        while (n--)
        {
            g += f;
            f = g - f;
        }
        return f;
    }
};

class Solution
{
  public:
    int jumpFloor(int number)
    {
        int Fib[number + 1];
        Fib[2] = 2;
        Fib[1] = 1;
        if (number <= 1)
            return number;
        for (int i = 3; i <= number; i++)
        {
            Fib[i] = Fib[i - 1] + Fib[i - 2];
        }
        return Fib[number];
    }
};
