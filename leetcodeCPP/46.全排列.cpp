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

// 回溯算法事实上就是一个树结构
// 返回时要进行状态重置
// 深度优先遍历

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
//                 // 如果当前元素还没有使用，那么就使用当前元素
//                 tmp.push_back(array[it]);
//                 visited[it] = true;
//                 // 如果满足一个全排列，那么就返回
//                 if (tmp.size() == n) {
//                     ret.push_back(tmp);
//                     return;
//                 // 否则，继续进行下一次回溯
//                 } else {
//                     backtrack(tmp, visited);
//                     // 要把最后的元素退出，并置当前元素为未访问状态
//                     // 状态与重置，为了能够继续进行下一次循环
//                     tmp.pop_back();
//                     visited[it] = false;
//                 }
//             }
//         }
//     }
// };

// class Solution {
// private:
//     vector<vector<int>> ret; // 保存结果
//     int n; // 数组长度

// public:
//     vector<vector<int>> permute(vector<int>& nums)
//     {
//         n = nums.size();
//         backtrack(nums, 0);
//         return ret;
//     }

//     void backtrack(vector<int>& nums, int begin)
//     {
//         if (begin >= n) {
//             ret.push_back(nums);
//             return;
//         }
//         for (int it = begin; it < n; it++) {
//             swap(nums[begin], nums[it]);
//             backtrack(nums, begin + 1);
//             // 要将交换过的元素还原
//             swap(nums[begin], nums[it]);
//         }
//     }
// };

// class Solution {
// private:
//     vector<vector<int>> ret; // 保存结果
//     int n; // 数组长度
//     vector<int> array;

// public:
//     vector<vector<int>> permute(vector<int>& nums)
//     {
//         n = nums.size();
//         array = nums;
//         vector<int> tmp; // 不带长度初始化，初始长度为0
//         vector<bool> visited(n, false); // 保存是否访问过
//         backtrack(tmp, visited);
//         return ret;
//     }

//     void backtrack(vector<int> tmp, vector<bool> visited)
//     {
//         // 定义递归退出条件
//         if (tmp.size() == n) {
//             ret.push_back(tmp);
//             return;
//         }

//         // 访问未访问过的元素
//         for (int it = 0; it < n; it++) {
//             // 如果还没有访问就访问
//             if (!visited[it]) {
//                 visited[it] = true;
//                 tmp.push_back(array[it]);
//                 // 继续遍历
//                 backtrack(tmp, visited);
//                 // 状态重置
//                 visited[it] = false;
//                 // 退回一步
//                 tmp.pop_back();
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
        // 递归结束条件
        if (begin == n) {
            ret.push_back(nums);
            return;
        }

        // 原地操作
        for (int it = begin; it < n; it++) {
            swap(nums[begin], nums[it]);
            backtrack(nums, begin + 1);
            // 要将交换过的元素还原
            swap(nums[begin], nums[it]);
        }
    }
};
