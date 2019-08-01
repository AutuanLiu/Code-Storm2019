/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (35.55%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    25.1K
 * Total Submissions: 69.9K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ret;
        // 首先对元素进行排序
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n - 3; a++) {
            // 去重
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            for (int b = a + 1; b < n - 2; b++) {
                if (b - 1 > a && nums[b] == nums[b - 1])
                    continue;
                // 确定了 a, b 之后，就要确定 c、d 使用两个指针进行搜索
                int left = b + 1, right = n - 1;
                while (left < right) {
                    int sumx = nums[a] + nums[b] + nums[left] + nums[right];
                    if (sumx == target) {
                        ret.push_back(vector<int>{ nums[a], nums[b], nums[left], nums[right] });

                        // 只有找到了满足条件的结果之后，才进行去重操作
                        // 这里是向后判断，因为我们的 left是加法
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        
                        // 这里是前向判断，因为我们的方向是前向
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }

                        // 只有成功的找到了，才一起变化，继续下一次
                        left++;
                        right--;
                    } else if (sumx < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ret;
    }
};
