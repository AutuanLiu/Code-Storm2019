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

class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> value;
        vector<int>::iterator ib1;
        ib1 = array.begin();
        while (ib1 != array.end())
        {
            if (*ib1 % 2 == 0)
            {
                value.push_back(*ib1);
                ib1 = array.erase(ib1);
            }
            else
            {
                ib1++;
            }
        }
        vector<int>::iterator ib2, ie2;
        ib2 = value.begin();
        ie2 = value.end();
        for (; ib2 != ie2; ib2++)
        {
            array.push_back(*ib2);
        }
    }
};
