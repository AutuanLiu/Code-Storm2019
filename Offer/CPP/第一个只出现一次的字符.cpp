// 第一个只出现一次的字符.cpp
// 哈希表
class Solution {
public:
    int FirstNotRepeatingChar(string str)
    {
        int n = str.length();
        map<char, int> dict;
        for (char& ch : str) {
            if (dict.find(ch) != dict.end())
                dict[ch] = dict[ch] + 1;
            else
                dict[ch] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (dict[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

// 固定长度的字符数组char的取值2^8 = 256
