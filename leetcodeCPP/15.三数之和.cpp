/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.78%)
 * Likes:    1067
 * Dislikes: 0
 * Total Accepted:    62.4K
 * Total Submissions: 273.9K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// **先搜索完，然后在去重**
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n < 3 || nums[0] + nums[1] + nums[2] > 0 || nums.back() < 0 || nums.front() > 0)
            return ret;
        for (int i = 0; i < n - 2; i++) {
            // 必须是和已经搜索过的元素进行比较
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;
            // 这里用一个 双指针
            int low = i + 1, high = n - 1;
            while (low < high) {
                int target = nums[i] + nums[low] + nums[high];
                if (target < 0)
                    low++;
                else if (target > 0)
                    high--;
                else {
                    ret.push_back({nums[i], nums[low], nums[high]});
                    // low 永远要小于 high
                    while (low + 1 < high && nums[low + 1] == nums[low])
                        low++;
                    while (high - 1 > low && nums[high - 1] == nums[high])
                        high--;
                    // 继续寻找下一组
                    low++;
                    high--;
                }
            }
        }
        return ret;
    }
};

