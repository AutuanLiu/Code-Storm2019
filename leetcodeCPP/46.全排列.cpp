/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (69.87%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    29.6K
 * Total Submissions: 42.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// 使用一个 visited 表示元素是否访问过
// 使用 private 来定义一些全局变量
// class Solution {
// private:
//     vector<vector<int>> ret;  // 保存结果
//     int n;  // 数组长度
//     vector<int> array;

// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         n = nums.size();
//         array = nums;
//         vector<int> tmp;  // 不带长度初始化，初始长度为0
//         vector<bool> visited(n, false);  // 保存是否访问过
//         backtrack(tmp, visited);
//         return ret;
//     }

//     void backtrack(vector<int> tmp, vector<bool> visited)
//     {
//         for (int it = 0; it < n; it++) {
//             if (!visited[it]) {
//                 tmp.push_back(array[it]);
//                 visited[it] = true;
//                 if (tmp.size() == n) {
//                     ret.push_back(tmp);
//                     return;
//                 } else {
//                     backtrack(tmp, visited);
//                     tmp.pop_back();
//                     visited[it] = false;
//                 }
//             }
//         }
//     }
// };

class Solution {
private:
    vector<vector<int>> ret; // 保存结果
    int n; // 数组长度

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        n = nums.size();
        backtrack(nums, 0);
        return ret;
    }

    void backtrack(vector<int>& nums, int begin)
    {
        if (begin >= n) {
            ret.push_back(nums);
            return;
        }
        for (int it = begin; it < n; it++) {
            swap(nums[begin], nums[it]);
            backtrack(nums, begin + 1);
            swap(nums[begin], nums[it]);
        }
    }
};
