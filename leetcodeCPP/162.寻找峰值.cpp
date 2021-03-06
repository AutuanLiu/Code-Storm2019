/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (40.16%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 31.9K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1]
 * 输出: 2
 * 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,2,1,3,5,6,4]
 * 输出: 1 或 5 
 * 解释: 你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 说明:
 * 
 * 你的解法应该是 O(logN) 时间复杂度的。
 * 
 */
// nums[i] ≠ nums[i+1]
// 分情况讨论
// 1. 单调增（最后一个元素） 2. 单调减（第一个元素） 3. 先增后减（中间元素） 4. 先减后增（第一个元素）
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         for (int it = 0; it < n - 1; it++) {
//             if (nums[it] > nums[it + 1])
//                 return it;
//         }
//         return n - 1;
//     }
// };

// 借助 二分查找 的思路
// 如果 mid 处于单调减区间，则说明 峰值出现在左边，如果 mid 处于单调增区间，说明增值出现在右边
// 时间和空间复杂度都是 O(log n)
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        //  当 Left == right 的时候 循环就会结束，此时所处的位置就是峰值的位置
        return left;
    }
};
