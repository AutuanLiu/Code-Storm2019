class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int length = numbers.size();
        if (length == 0)
            return 0;
        sort(numbers.begin(), numbers.end());
        int max_num = 0;
        int num = 0;
        int val = numbers[0];
        for (int i = 0; i < length; i++)
        {
            if (val == numbers[i])
            {
                num++;
            }
            else
            {
                max_num = num > max_num ? num : max_num;
                if (max_num > length / 2)
                    return val;
                val = numbers[i];
                num = 1;
            }
        }
        max_num = num > max_num ? num : max_num;
        if (max_num > length / 2)
            return val;
        else
            return 0;
    }
};

class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        vector<int> tmp(numbers);

        if (numbers.size() == 0)
            return 0;
        else if (numbers.size() == 1)
            return numbers[0];
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0)
                continue;
            for (int j = i + 1; j < numbers.size(); j++)
                if (numbers[i] != numbers[j] && numbers[j] != 0)
                {
                    numbers[i] = 0;
                    numbers[j] = 0;
                    break;
                }
        }
        int j = 0;
        for (int i = 0; i < numbers.size(); i++)
            if (numbers[i] != 0)
                j = i;
        int num = count(tmp.begin(), tmp.end(), numbers[j]);
        if (num > numbers.size() / 2)
            return numbers[j];
        else
            return 0;
    }
};

class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size() <= 0)
            return 0;

        int count = 1;
        int temp = numbers[0];
        int length = numbers.size();
        for (int i = 1; i < length; i++)
        {
            if (count == 0)
            {
                temp = numbers[i];
                count = 1;
            }
            else if (numbers[i] == temp)
                count++;
            else
                count--;
        }

        int result = temp;

        int times = 0;
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] == result)
                times++;
        }
        if (times <= length / 2)
            return 0;
        else
            return result;
    }
};
