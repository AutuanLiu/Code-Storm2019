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
