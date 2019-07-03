/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (44.33%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    50.3K
 * Total Submissions: 113.5K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// 一般需要原地更改的都考虑从后往前进行遍历，否则就涉及到移动元素的问题
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int k = m + n - 1, p1 = m - 1, p2 = n - 1; k >= 0; k--) {
            if (p1 < 0) {
                nums1[k] = nums2[p2--];
                continue;
            }
            if (p2 < 0) {
                nums1[k] = nums1[p1--];
                continue;
            }
            // 上述两个条件只要满足一个就可以终止本次循环，进行下一次循环
            if (nums1[p1] < nums2[p2])
                nums1[k] = nums2[p2--];
            else
                nums1[k] = nums1[p1--];
        }
    }
};

// 排序
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for (int i = 0, t = m; i < n; i++)
//             nums1[t++] = nums2[i];
//         // 排序
//         sort(nums1.begin(), nums1.begin() + m + n);
//     }
// };
