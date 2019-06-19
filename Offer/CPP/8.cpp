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
        if (number <= 2)
            return number;
        int Fib3, Fib1 = 1, Fib2 = 2;
        for (int i = 3; i <= number; i++)
        {
            Fib3 = Fib1 + Fib2;
            Fib1 = Fib2;
            Fib2 = Fib3;
        }
        return Fib3;
    }
};

class Solution
{
  public:
    int jumpFloor(int number)
    {
        int Fib[number + 1];
        Fib[1] = 1;
        Fib[2] = 2;
        for (int i = 3; i <= number; i++)
        {
            Fib[i] = Fib[i - 1] + Fib[i - 2];
        }
        return Fib[number];
    }
};
