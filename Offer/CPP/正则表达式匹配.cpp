// 正则表达式匹配
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        // 字符串或者模式只要有一个为 空 就认为不匹配
        if (str == nullptr || pattern == nullptr)
            return false;
        // 字符串和模式都只有字符串结束标志 那么其是相互匹配的
        if (*pattern == '\0')
            return *str == '\0';
        // 如果模式的第二个字符是 *
        if (*(pattern + 1) == '*') {
            // 如果字符串和模式的第一个字符相等 或者 （模式的第一个字符是 . 并且字符串的位置不是结束符）
            // 那么只要 *匹配1个字符 或者 *匹配多个字符 或者 *匹配0个字符 即匹配
            if (*pattern == *str || (*pattern == '.' && *str != '\0'))
                return match(str + 1, pattern + 2) || match(str + 1, pattern) || match(str, pattern + 2);
            // 当前字符串字符和模式字符不相等并且模式字符不是 .
            else
                return match(str, pattern + 2);
        }
        // 如果模式的字符是 . 或者模式和字符串的字符相等 则继续匹配下一个字符
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return match(str + 1, pattern + 1);
        return false; // 其他情况下都是不匹配 false
    }
};