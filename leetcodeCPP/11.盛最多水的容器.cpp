/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (56.09%)
 * Likes:    604
 * Dislikes: 0
 * Total Accepted:    51.3K
 * Total Submissions: 91.5K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */
// 双指针法
// 短板效应
// 不断将指向较短线段的指针向较长线段那端移动
// 在同样的条件下，移动指向较短线段的指针尽管造成了矩形宽度的减小，但却可能会有助于面积的增大
// 因为移动较短线段的指针可能会得到一条相对较长的线段，这可以克服由宽度减小而引起的面积减小

class Solution
{
public:
    int maxArea(vector<int>& height) {
        int ret = 0, lb = 0, rb = height.size() - 1;
        // 左边界 lb 只能小于右边界 rb
        while (lb < rb) {
            // 先计算再更新
            ret = max(ret, (rb - lb) * min(height[lb], height[rb]));
            if (height[lb] < height[rb])
                lb++;
            else
                rb--;
        }
        return ret;
    }
};

