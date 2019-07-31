/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode-cn.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (61.26%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 21.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i]
 * 之外其余各元素的乘积。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * 
 */

// 当前数左边的乘积 * 当前数右边的乘积
// 上三角 小三角
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        // 先分配空间然后才能赋值
        int n = nums.size();
        vector<int> ret(n);

        // 计算左边的乘积
        for (int it = 0, tmp = 1; it < n; it++) {
            ret[it] = tmp; // 左边的乘积，没有左边元素的时候 乘积就是 1
            tmp *= nums[it];
        }

        // 计算结果
        for (int it = n - 1, tmp = 1; it >= 0; it--) {
            ret[it] = tmp * ret[it];
            // 右边的乘积乘以左边的乘积，ret[it] 已经存储了左边元素的累积乘积
            // tmp 保存的是右边元素的累积乘积，没有右边元素的时候，乘积为 1、
            tmp *= nums[it];
        }
        return ret;
    }
};
