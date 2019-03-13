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
