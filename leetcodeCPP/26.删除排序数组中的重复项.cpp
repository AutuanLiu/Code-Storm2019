/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (44.85%)
 * Likes:    926
 * Dislikes: 0
 * Total Accepted:    130.4K
 * Total Submissions: 290.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 * 
 * 示例 1:
 * 
 * 给定数组 nums = [1,1,2], 
 * 
 * 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
 * 
 * 你不需要考虑数组中超出新长度后面的元素。
 * 
 * 示例 2:
 * 
 * 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 * 
 * 你不需要考虑数组中超出新长度后面的元素。
 * 
 * 
 * 说明:
 * 
 * 为什么返回数值是整数，但输出的答案是数组呢?
 * 
 * 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 * 
 * 你可以想象内部操作如下:
 * 
 * // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 * int len = removeDuplicates(nums);
 * 
 * // 在函数里修改输入数组对于调用者是可见的。
 * // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 * 
 */
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 1)
//             return n;
//         int ln = 1, last = nums[0];
//         for (int it = 1; it < n; it++) {
//             if (nums[it] > last) {
//                 nums[ln++] = nums[it];
//                 last = nums[it];
//             }
//         }
//         return ln;
//     }
// };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums)
//     {
//         int n = nums.size(), ln = 0;
//         for (int it = 0, last = INT_MIN; it < n; it++) {
//             if (nums[it] > last) {
//                 nums[ln++] = nums[it];
//                 last = nums[it];
//             }
//         }
//         return ln;
//     }
// };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums)
//     {
//         int n = nums.size(), ln = 0, last = INT_MIN;
//         for (int& it : nums) {
//             if (it > last) {
//                 nums[ln++] = it;
//                 last = it;
//             }
//         }
//         return ln;
//     }
// };


class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int slow = 0, fast = 1;

        while (fast < n) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};