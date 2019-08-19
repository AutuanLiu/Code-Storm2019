/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (38.54%)
 * Likes:    861
 * Dislikes: 0
 * Total Accepted:    84.9K
 * Total Submissions: 220.1K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
// 栈
class Solution {
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;
        stack<char> sk;
        unordered_map<char, char> m = { { ')', '(' }, { ']', '[' }, { '}', '{' } };
        for (char& c : s) {
            // 左括号就入栈
            if (c == '(' || c == '[' || c == '{')
                sk.push(c);
            // 右括号就判断
            if (c == ')' || c == ']' || c == '}') {
                if (!sk.empty() && sk.top() == m[c])
                    sk.pop();
                else
                    return false;
            }
        }
        // 栈为空才是有效括号串
        return sk.empty();
    }
};
