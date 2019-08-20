#include "leetcode_repos.h"

class Solution {
public:
    inline void getSubset(vector<int>& nums, vector<int>& path, vector<vector<int>>& ret, int level = 0)
    {
        int m = path.size(), n = nums.size();
        if (m <= n)
            ret.push_back(path);
        for (int i = level; i < n; i++) {
            path.push_back(nums[i]);
            getSubset(nums, path, ret, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> path;
        getSubset(nums, path, ret);
        return ret;
    }

    vector<vector<int>> subsets1(vector<int>& nums)
    {
        vector<vector<int>> ret(1); // 包含空
        for (int& item : nums) {
            int m = ret.size();
            for (int i = 0; i < m; i++) {
                vector<int> tmp(ret[i]);
                tmp.push_back(item);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums{ 1, 2, 3, 4 };
    vector<vector<int>> ret = Solution().subsets(nums);
    print_matrix(ret);

    vector<vector<int>> ret1 = Solution().subsets1(nums);
    print_matrix(ret1);
}