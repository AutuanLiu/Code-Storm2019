class Solution
{
  public:
    int NumberOf1(int n)
    {
        int count = 0;
        if (n < 0)
            count++;
        int num = n;
        if (n < 0)
            num = 2147483647 + n + 1;
        while (num > 0)
        {
            if (num & 1)
            {
                count++;
            }
            num >>= 1;
        }
        return count;
    }
};

class Solution
{
  public:
    int NumberOf1(int n)
    {

        int count = 0;
        while (n != 0)
        {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
};

class Solution
{
  public:
    int NumberOf1(int n)
    {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
            {
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }
};
