// 双指针
class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                    swap(array[j], array[j - 1]);
            }
        }
    }
};

// 新创建一个数组，将奇数和偶数分别放进去
class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> result;
        int num = array.size();
        for (int i = 0; i < num; i++)
        {
            if (array[i] % 2 == 1)
                result.push_back(array[i]);
        }
        for (int i = 0; i < num; i++)
        {
            if (array[i] % 2 == 0)
                result.push_back(array[i]);
        }
        array = result;
    }
};


