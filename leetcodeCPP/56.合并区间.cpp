/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.49%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 52K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */
class Solution {
public:
    // 这里必须是 static 方法
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.empty())
            return {};
        // 先按照 左端点的数值进行排序
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ret = { intervals[0] };
        int n = intervals.size();
        for (auto& item : intervals) {
            if (ret.back()[1] >= item[0])
                ret.back()[1] = max(ret.back()[1], item[1]);
            else
                ret.push_back(item);
        }
        return ret;
    }
};
