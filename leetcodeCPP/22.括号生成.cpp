/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (70.49%)
 * Likes:    407
 * Dislikes: 0
 * Total Accepted:    26.3K
 * Total Submissions: 37.3K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// 回溯法
// 能进则进，进不了则换(分支)，换不了则退(递归)
// 回溯法的关键：找到递归的出口
// class Solution
// {
//   public:
//     vector<string> generateParenthesis(int n)
//     {
//         vector<string> ret;
//         backtrack(ret, "", 0, 0, n);
//         return ret;
//     }

//     void backtrack(vector<string>& ret, string tmp, int left, int right, int n)
//     {
//         // 回溯的出口
//         if (tmp.length() == 2 * n) {
//             ret.push_back(tmp);
//             return;
//         }
//         if (left < n)
//             backtrack(ret, tmp + "(", left + 1, right, n);
//         if (right < left)
//             backtrack(ret, tmp + ")", left, right + 1, n);
//     }
// };

class Solution {
private:
    vector<string> ret;
    int ln;

public:
    vector<string> generateParenthesis(int n)
    {
        ln = n;
        backtrack("", 0, 0);
        return ret;
    }

    void backtrack(string tmp, int left, int right)
    {
        // 回溯的出口
        if (tmp.length() == 2 * ln) {
            ret.push_back(tmp);
            return;
        }
        if (left < ln)
            backtrack(tmp + "(", left + 1, right);
        if (right < left)
            backtrack(tmp + ")", left, right + 1);
    }
};
