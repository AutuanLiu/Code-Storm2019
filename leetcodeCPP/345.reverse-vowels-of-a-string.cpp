/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (45.71%)
 * Total Accepted:    6.1K
 * Total Submissions: 13.3K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */
// 双指针
class Solution {
private:
    // 包含大小写
    set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

public:
    string reverseVowels(string s)
    {
        if (s.empty())
            return s;
        int n = s.size();
        int left = 0, right = n - 1;
        // left == right 不用交换
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }

            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }

            // 继续进行下一次交换，这里必须更新，否则就会一直在原地无限交换
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
