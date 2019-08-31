/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (49.24%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 32.1K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 你可以假设数组中不存在重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 * 
 */
// 存在一个分界点 当升序数组分为两个升序子数组
// 左边的大，右边的小，右边升序子数组的第一个元素就是全局最小值
// 也有可能分界点在 ix = 0 , 那么 nums[0] 就是全局最小值
// 假设数组中不存在重复元素
// class Solution {
// public:
//     int findMin(vector<int>& nums)
//     {
//         int n = nums.size();
//         // if (n == 1)
//         //     return nums[0];
//         // 遍历数组 找到分界点
//         for (int pos = 1; pos < n; pos++) {
//             if (nums[pos] < nums[pos - 1])
//                 return nums[pos];
//         }
//         return nums[0];
//     }
// };

// 二分法
// 不存在重复元素
// 当nums[mid] > nums[right]说明在mid左半边的递增区域, 说明最小元素在> mid区域
// 当nums[mid] < nums[right说明在mid右半边的递增区域, 说明最小元素在<= mid区域

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
        }
        return nums[left];
    }
};
