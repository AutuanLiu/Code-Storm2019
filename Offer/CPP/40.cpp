class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.size() < 2)
            return;

        int resultExclusiveOR = 0;
        for (int i = 0; i < data.size(); i++)
        {
            resultExclusiveOR ^= data[i];
        }

        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

        *num1 = *num2 = 0;
        for (int j = 0; j < data.size(); j++)
        {
            if (IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }
    }

    unsigned int FindFirstBitIs1(int num)
    {
        int indexBit = 0;
        while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            indexBit++;
        }

        return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return (num & 1);
    }
};

class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {

        int len = data.size();
        if (len <= 2)
            return;

        int one = 0;
        for (int i = 0; i < len; i++)
        {
            one = one ^ data[i];
        }

        int pos = 0;
        int flag = 1;
        while (flag)
        {
            if (one & flag)
                break;
            flag = flag << 1;
            pos++;
        }

        for (int i = 0; i < len; i++)
        {
            if ((data[i] & flag))
                *num1 = *num1 ^ data[i];
            else
                *num2 = *num2 ^ data[i];
        }
    }
};

class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        int size = data.size();
        map<int, int> mp;
        for (int i = 0; i < size; ++i)
        {
            mp[data[i]]++;
        }
        map<int, int>::iterator it;
        int m = 0;
        for (it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second == 1)
            {
                if (m == 0)
                {
                    *num1 = it->first;
                    ++m;
                }
                else
                {
                    *num2 = it->first;
                    break;
                }
            }
        }
    }
};
