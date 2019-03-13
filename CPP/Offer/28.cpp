// 一次遍历
class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size() == 0)
            return 0;

        int count = 1;  // count 的初始值
        int res = numbers[0];  // 用于保存结果
        for (int i = 1; i < numbers.size(); i++)
        {
            if (count == 0)
            {
                res = numbers[i];
                count = 1;
            }
            else if (numbers[i] == res)
                count++;
            else
                count--;
        }

        // 用于判断结果是否满足要求
        int times = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == res)
                times++;
        }

        if (times <= numbers.size() / 2)
            return 0;
        else
            return res;
    }
};
