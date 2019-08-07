/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (50.19%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    34.4K
 * Total Submissions: 68.5K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
class Solution {
private:
    map<char, string> i2s = {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };

public:
    void letterCombinations(int n, int start, string& str, const string& digits, vector<string>& ret)
    {
        // 递归出口
        if (start == n)
            ret.push_back(str);
        for (char& c : i2s[digits[start]]) {
            str.push_back(c);
            letterCombinations(n, start + 1, str, digits, ret);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> ret;
        int n = digits.size();
        string str = "";
        letterCombinations(n, 0, str, digits, ret);
        return ret;
    }
};
