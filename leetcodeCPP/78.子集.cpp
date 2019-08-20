/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (74.26%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 38.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
// class Solution {
// public:
//     inline void getSubset(vector<int>& nums, vector<int>& path, vector<vector<int>>& ret, int level = 0)
//     {
//         int m = path.size(), n = nums.size();
//         if (m <= n)
//             ret.push_back(path);
//         for (int i = level; i < n; i++) {
//             path.push_back(nums[i]);
//             getSubset(nums, path, ret, i + 1);
//             path.pop_back();
//         }
//     }

//     vector<vector<int>> subsets(vector<int>& nums)
//     {
//         int n = nums.size();
//         vector<vector<int>> ret;
//         vector<int> path;
//         getSubset(nums, path, ret);
//         return ret;
//     }
// };

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ret(1); // 包含空
        for (int& item : nums) {
            int m = ret.size();  // 这里必须计算遍历次数
            for (int i = 0; i < m; i++) {
                vector<int> tmp(ret[i]);
                tmp.push_back(item);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
