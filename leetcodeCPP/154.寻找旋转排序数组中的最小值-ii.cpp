/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (44.72%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 14.8K
 * Testcase Example:  '[1,3,5]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 注意数组中可能存在重复的元素。
 * 
 * 示例 1：
 * 
 * 输入: [1,3,5]
 * 输出: 1
 * 
 * 示例 2：
 * 
 * 输入: [2,2,2,0,1]
 * 输出: 0
 * 
 * 说明：
 * 
 * 
 * 这道题是 寻找旋转排序数组中的最小值 的延伸题目。
 * 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 * 
 * 
 */
// 二分法
// 存在重复元素
// 当 nums[mid] > nums[right] 说明mid左半边的递增区域, 说明最小元素在> mid区域
// 当 nums[mid] < nums[right] 说明mid右半边的递增区域, 说明最小元素在<= mid区域
// 当 nums[mid] = nums[right] 说明
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[right] < nums[mid])
                left = mid + 1;
            else if (nums[right] > nums[mid])
                right = mid;
            else
                right--;
        }
        return nums[left];
    }
};

// 搜索法 只要找到第一个小于左边的元素即可，如果都相等，那么返回第一个元素即可
// class Solution {
// public:
//     int findMin(vector<int>& nums)
//     {
//         int n = nums.size();
//         // 遍历数组 找到分界点
//         for (int pos = 1; pos < n; pos++) {
//             if (nums[pos] < nums[pos - 1])
//                 return nums[pos];
//         }
//         return nums[0];
//     }
// };
