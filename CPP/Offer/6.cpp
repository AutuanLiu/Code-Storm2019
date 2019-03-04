class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        sort(rotateArray.begin(), rotateArray.end());

        return rotateArray[0];
    }
};

class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int min = 65563;
        if (!rotateArray.empty())
        {
            for (int i = 0; i < rotateArray.size(); i++)
            {
                if (min > rotateArray.at(i))
                    min = rotateArray.at(i);
            }
            return min;
        }
        else
            return 0;
    }
};

class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {

        int size = rotateArray.size();
        if (size == 0)
            return 0;

        int i = 0;
        bool flag = false;
        for (i = 0; i < size - 1; i++)
        {
            if (rotateArray[i] > rotateArray[i + 1])
            {
                flag = true;
                break;
            }
        }

        if (flag)
            return rotateArray[i + 1];
        else
            return rotateArray[0];
    }
};
