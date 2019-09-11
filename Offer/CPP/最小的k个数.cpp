// 最小的k个数.cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int n = input.size();
        vector<int> vec;
        if (n < k)
            return vec;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; i++)
            vec.push_back(input[i]);
        return vec;
    }
};


// 堆排序
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int n = input.size();
        vector<int> vec;
        if (n < k)
            return vec;
        
        return vec;
    }
};