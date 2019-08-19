/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (57.30%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    35.4K
 * Total Submissions: 61.2K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// 排序的方法
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k)
//     {
//         sort(nums.begin(), nums.end(), greater<int>());
//         return nums[k - 1];
//     }
// };

// 快速排序的思路
// 使用一个大小为 K 的小根堆
// 当遍历完所有的数据之后，堆顶元素就是所求
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k)
//     {
//         int n = nums.size();
//         // 构造大小为 k 的小根堆
//         vector<int> heap(nums.begin(), nums.begin() + k);
//         make_heap(heap.begin(), heap.end(), greater<int> ());
//         // 此时最小元素就保存在 heap 的第一个位置

//         // 遍历剩余的元素
//         for (int it = k; it < n; it++) {
//             // 当当前元素大于最小元素，则要加入新的元素到堆
//             if (nums[it] > heap[0]) {
//                 heap.push_back(nums[it]);  // 加入新的元素
//                 // 移动新的元素到合适的位置
//                 push_heap(heap.begin(), heap.end(), greater<int> ());

//                 // 新加入一个元素，必然导致数组数量超过 k，那么要进行删除
//                 // 移动最小的元素到数组结尾
//                 pop_heap(heap.begin(), heap.end(), greater<int> ());
//                 heap.pop_back();
//             }
//         }
//         return heap[0];
//     }
// };

//  使用优先队列，使用堆构造的
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int& item : nums) {
            heap.push(item);
            if (heap.size() > k)
                heap.pop();
        }
        return heap.top();
    }
};

// 使用快速排序
