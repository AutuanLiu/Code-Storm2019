class Solution
{
  public:
    int Fibonacci(int n)
    {
        int first = 0;
        int second = 1;

        int result = n;
        for (int i = 2; i <= n; i++)
        {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};

class Solution
{
  public:
    int Fibonacci(int n)
    {
        if (n < 2)
            return n;
        int a = 0, b = 1, result = 0;
        for (int i = 1; i < n; i++)
        {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};
