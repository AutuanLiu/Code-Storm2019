/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.58%)
 * Likes:    1024
 * Dislikes: 0
 * Total Accepted:    66.2K
 * Total Submissions: 144.8K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int ret = nums[0], tmp = nums[0], n = nums.size();
//         for (int it = 1; it < n; it++) {
//             tmp = tmp + nums[it] < nums[it] ? nums[it] : tmp + nums[it];
//             ret = max(tmp, ret);
//         }
//         return ret;
//     }
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums)
//     {
//         int ret = INT_MIN, tmp = INT_MIN;
//         for (int& it : nums) {
//             tmp = tmp + it < it ? it : tmp + it;
//             ret = max(tmp, ret);
//         }
//         return ret;
//     }
// };

// 原地操作
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        for (int it = 1; it < nums.size(); it++) {
            nums[it] = max(nums[it], nums[it - 1] + nums[it]);
        }
        return *max_element(nums.begin(), nums.end());
    }
};
