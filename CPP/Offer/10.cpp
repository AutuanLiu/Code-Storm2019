class Solution
{
  public:
    int rectCover(int number)
    {
        if (number <= 0)
        {
            return number;
        }
        int f1 = 1;
        int f2 = 2;
        int f3;

        for (int i = 3; i <= number; i++)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};

class Solution
{
  public:
    int rectCover(int number)
    {
        if (number == 0)
        {
            return 0;
        }
        if (number == 1)
        {
            return 1;
        }
        int rect1 = 1;
        int rect2 = 0;
        int result = 0;
        for (int i = 0; i < number; i++)
        {
            result = rect1 + rect2;
            rect2 = rect1;
            rect1 = result;
        }
        return result;
    }
};

class Solution
{
  public:
    int rectCover(int number)
    {
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        int f1 = 1;
        int f2 = 2;
        int fn;
        for (int i = 3; i <= number; i++)
        {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};
