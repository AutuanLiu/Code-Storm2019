/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 *
 * https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/description/
 *
 * algorithms
 * Medium (39.96%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 4.3K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。
 * 
 * 返回使 A 中的每个值都是唯一的最少操作次数。
 * 
 * 示例 1:
 * 
 * 输入：[1,2,2]
 * 输出：1
 * 解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
 * 
 * 示例 2:
 * 
 * 输入：[3,2,1,2,1,7]
 * 输出：6
 * 解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
 * 可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 40000
 * 0 <= A[i] < 40000
 * 
 * 
 */
// 相当于 hash 表解决冲突的问题
// 先统计每个数字出现的次数 数字的范围是在 0 到 80000
// 对于每个数字 如果他是重复的就减去那个数字，如果是没有出现 那么就加上那个数字

// 由于我们的目标是使数组中所有数字都变成唯一，那么当某个数字是i的时候，它的下一个数字至少应该是i+1。
// 如果下一个数字小于i+1，我们就需要增加它，增加的次数即为数字与i+1之间的差值。
// 而且从前往后扫描 存在一定的贪心思想

// 或者找到未出现的数值 和 重复数值 逐一相减并求和

class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
        int n = A.size();
        if (n == 0)
            return 0;
        sort(A.begin(), A.end()); // 从小到大进行排序
        int prev = A[0], ret = 0;

        for (int i = 1; i < n; i++) {
            if (A[i] <= prev) {
                ret += prev + 1 - A[i]; // prev + 1 还没有被使用
                A[i] = prev + 1;
            }
            prev = A[i]; // 更新 prev 数值
        }
        return ret;
    }
};
