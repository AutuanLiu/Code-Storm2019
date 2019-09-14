// 把数组排成最小的数.cpp
class Solution {
public:
    string PrintMinNumber(vector<int> nums)
    {
        int n = nums.size();
        if (n == 0)
            return "";
        sort(nums.begin(), nums.end(),
            [](int a, int b) -> bool { return (to_string(a) + to_string(b)) < to_string(b) + to_string(a); });
        string ret;
        for (int i = 0; i < n; i++)
            ret += to_string(nums[i]);
        return ret;
    }
};
