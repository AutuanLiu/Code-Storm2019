class Solution
{
  public:
    int rectCover(int number)
    {
        if (number <= 2)
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

