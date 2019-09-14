/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (52.72%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    14.7K
 * Total Submissions: 27.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
// 带剪枝的全排列
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> array;
    int n;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        // sort 是原地操作， 没有返回值
        // 这里要排序，使得重复元素在一起
        sort(nums.begin(), nums.end());
        array = nums;
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> tmp;
        backtrack(tmp, visited);
        return ret;
    }

    void backtrack(vector<int>& tmp, vector<bool>& visited)
    {
        // 定义递归终止条件
        if (tmp.size() == n) {
            ret.push_back(tmp);
            return;
        }

        // 遍历
        for (int it = 0; it < n; it++) {
            if (!visited[it]) {
                // 和之前的数相等，并且之前的数还未使用过，只有出现这种情况，才会出现相同分支
                if (it > 0 && !visited[it - 1] && array[it] == array[it - 1])
                    continue;
                visited[it] = true;
                tmp.push_back(array[it]);
                backtrack(tmp, visited);
                visited[it] = false;
                tmp.pop_back();
            }
        }
        return;
    }
};
