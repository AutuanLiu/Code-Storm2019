/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (31.73%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 27.7K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */
class Solution {
private:
    // 缓存，保存最大的三个数
    vector<long long> cache{ LLONG_MIN, LLONG_MIN, LLONG_MIN };

public:
    int thirdMax(vector<int>& nums)
    {
        for (int it = 0; it < nums.size(); it++) {
            // 如果当前值比缓存池的最小值大, 那么当前值就是最小值
            if (nums[it] > cache[0]) {
                cache[2] = cache[1];
                cache[1] = cache[0];
                cache[0] = nums[it];
            } else if (nums[it] > cache[1] && nums[it] < cache[0]) {
                cache[2] = cache[1];
                cache[1] = nums[it];
            } else if (nums[it] > cache[2] && nums[it] < cache[1]) {
                cache[2] = nums[it];
            }
        }
        return cache[2] != LLONG_MIN ? cache[2] : cache[0];
    }
};

// class Solution {
// public:
//     int thirdMax(vector<int>& nums)
//     {
//         // set 本事是有序的，红黑树实现
//         set<int> cache;
//         for (int& it : nums) {
//             cache.insert(it);
//             // 控制缓存池的长度，不让其超过 3
//             if (cache.size() > 3)
//                 cache.erase(cache.begin());
//         }
//         return cache.size() == 3 ? *cache.begin() : *cache.rbegin();
//     }
// };
