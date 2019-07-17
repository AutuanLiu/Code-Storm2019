/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.60%)
 * Likes:    749
 * Dislikes: 0
 * Total Accepted:    80.4K
 * Total Submissions: 129.5K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */
// 异或操作
// 除了某个元素只出现一次以外，其余每个元素均出现两次
// 相同元素取异或结果为 0
// a^a=0; 0^b=b; b^b=0;
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ret = nums[0], n = nums.size();
//         for (int i = 1; i < n; i++) {
//             ret = ret ^ nums[i];
//         }
//         return ret;
//     }
// };

// class Solution {
// public:
//     int singleNumber(vector<int>& nums)
//     {
//         int ret = 0;
//         for (int& it:nums) {
//             ret = ret ^ it;
//         }
//         return ret;
//     }
// };

// 除了某个元素只出现一次以外，其余每个元素均出现两次
// 所以使用单个元素的两倍减去原来的元素和就是单个元素
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_set<int> os(nums.begin(), nums.end());
        int s1 = accumulate(os.begin(), os.end(), 0);
        int s2 = accumulate(nums.begin(), nums.end(), 0);
        return 2 * s1 - s2;
    }
};
