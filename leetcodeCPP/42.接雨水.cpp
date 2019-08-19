/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (44.38%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 36.8K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// 暴力
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int ret = 0, n = height.size();
//         // 第一个肯定是不蓄水的， 如果 n <= 1, 0
//         for (int i = 1; i < n; i++) {
//             // 向左搜索, 每个元素都有左边的最大和右边的最大
//             // 搜索的时候应当包含当前元素
//             int max_left = 0, max_right = 0;
//             for (int j = i; j >= 0; j--)
//                 max_left = max(max_left, height[j]);
//             // 向右搜索
//             for (int j = i; j < n; j++)
//                 max_right = max(max_right, height[j]);
//             // 这里因为宽度是 1
//             ret += min(max_left, max_right) - height[i];
//         }
//         return ret;
//     }
// };

// 动态规划，也就是保存每个元素对应的max_left 和 max_right 值
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int ret = 0, n = height.size();
//         if (n <= 1)
//             return ret;
//         vector<int> max_left(n), max_right(n);
//         // 备忘录的方法
//         max_left[0] = height[0];
//         max_right[n - 1] = height[n - 1];
//         for (int i = 1; i < n; i++)
//             max_left[i] = max(max_left[i - 1], height[i]);
//         for (int i = n - 2; i >= 0; i--)
//             max_right[i] = max(max_right[i + 1], height[i]);

//         // 遍历计算
//         for (int i = 0; i < n; i++)
//             ret += min(max_left[i], max_right[i]) - height[i];
//         return ret;
//     }
// };

// 双指针，就是用 两个指针同时滑动代表一个遍历的过程
// 短的一方逐渐向长的一方靠近
class Solution {
public:
    int trap(vector<int>& height)
    {
        int ret = 0, n = height.size();
        if (n <= 1)
            return ret;
        int left = 0, right = n - 1;
        int max_left = 0, max_right = 0;

        // 遍历一次
        while (left < right) {
            // 储水量由 max_left 决定
            if (height[left] < height[right]) {
                if (max_left > height[left])
                    ret += max_left - height[left++];
                else
                    max_left = height[left++];
            } else {
                // 储水量由 max_right 决定
                if (max_right > height[right])
                    ret += max_right - height[right--];
                else
                    max_right = height[right--];
            }
        }
        return ret;
    }
};
