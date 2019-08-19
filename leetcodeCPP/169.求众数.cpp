/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (59.70%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    50.1K
 * Total Submissions: 83.7K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         // sort 函数原地操作
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() / 2];
//     }
// };

// 使用hash表统计
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> counts;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (++counts[nums[i]] > n / 2)
                return nums[i];
        }
        return 0;
    }
};
