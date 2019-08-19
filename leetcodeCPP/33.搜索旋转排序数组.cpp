/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.56%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    29.1K
 * Total Submissions: 79.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            // nums[mid]和第一个元素比较，如果大于说明左边是一个递增区域（分割点在mid右边），
            // 搜索左边
            if (nums[mid] >= nums[0]) {
                // target 在 mid 和 right 中间
                // 左边是递增区域，所以判断 target是否在 nums[0] 和 nums[mid] 之间
                if (target >= nums[0] && target < nums[mid])
                    right = mid - 1;
                // target 不在 mid 和 right 中间，那么target在左半部分
                else
                    left = mid + 1;
                // 分割点在左边， 右半部分是一个递增区域
            } else {
                if (target > nums[mid] && target < nums[0])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        // 如果上述没有返回，则表示没有找到 target，返回 -1
        return -1;
    }
};
