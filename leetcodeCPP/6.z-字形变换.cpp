/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (42.94%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    37.4K
 * Total Submissions: 87.1K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */
// 基于方向和行数
// 需要计算出非空行的个数
// 先按行得到中间结果，之后在进行拼接
// direction=1表示向下-1表示向上
class Solution {
public:
    string convert(string s, int numRows)
    {
        string ret;
        int direction = -1, curr_row = 0;
        if (numRows == 1)
            return s;
        // s.size() 必须进行类型转换
        vector<string> tmp(min(numRows, int(s.size())));
        for (char& c : s) {
            tmp[curr_row] += c;
            if (curr_row == numRows - 1 || curr_row == 0)
                direction *= -1;
            curr_row += direction;
        }

        // 拼接结果
        for (string& it : tmp)
            ret += it;
        return ret;
    }
};
