class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int len = input.size();
        vector<int> vec;
        if (len < k)
            return vec;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; i++)
            vec.push_back(input[i]);
        return vec;
    }
};

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {

        vector<int> v;
        if (k > input.size())
            return v;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; i++)
            v.push_back(input[i]);
        return v;
    }
};

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {

        vector<int> result;
        if (input.size() == 0 || k == 0 || k > input.size())
        {
            return result;
        }
        for (int i = input.size() / 2 - 1; i >= 0; i--)
        { //初始化堆

            adjustHeap(input, i, k);
        }
        int i = k;
        while (i < input.size())
        {

            if (input[0] > input[i])
            {
                int temp = input[i];
                input[i] = input[0];
                input[0] = temp;
                adjustHeap(input, 0, k);
                i = k;
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < k; i++)
        {

            result.push_back(input[i]);
        }

        return result;
    }

    void adjustHeap(vector<int> &input, int i, int length)
    { //堆调整

        int child = i * 2 + 1;
        if (child < length)
        {

            if (child + 1 < length && input[child + 1] > input[child])
            {
                child = child + 1;
            }
            if (input[child] > input[i])
            {
                int temp = input[i];
                input[i] = input[child];
                input[child] = temp;
                adjustHeap(input, child, length);
            }
        }
    }
    void heapSort(vector<int> &input, int length)
    { //堆排序
        for (int i = length / 2 - 1; i >= 0; i--)
        { //初始化堆

            adjustHeap(input, i, length);
        }

        for (int i = length - 1; i > 0; i--)
        {
            int temp = input[i];
            input[i] = input[0];
            input[0] = temp;
            adjustHeap(input, 0, i);
        }
    }
};
