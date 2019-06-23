/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (40.94%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 70.4K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2], n = nums.size();
        for (int i = 0; i < n; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int tmp = nums[i] + nums[low] + nums[high];
                if (abs(target - tmp) < abs(target - ret))
                    ret = tmp;
                if (tmp < target)
                    low++;
                else if (tmp > target)
                    high--;
                else
                    return target;
            }
        }
        return ret;
    }
};

