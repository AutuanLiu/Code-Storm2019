class Solution {
public:
    void ReverseWord(string& str, int left, int right)
    {
        while (left < right) {
            swap(str[left++], str[right--]);
        }
    }

    string ReverseSentence(string str)
    {
        int n = str.length();
        if (n == 0)
            return "";
        ReverseWord(str, 0, n - 1); //先整体翻转
        int s = 0, e = 0;
        int i = 0;
        while (i < n) {
            while (i < n && str[i] == ' ') //空格跳过
                i++;
            e = s = i; //记录单词的第一个字符的位置
            while (i < n && str[i] != ' ') //不是空格 找单词最后一个字符的位置
            {
                i++;
                e++;
            }
            ReverseWord(str, s, e - 1); //局部翻转
        }
        return str;
    }
};

class Solution {
public:
    string ReverseSentence(string str)
    {
        string ret = "", tmp = "";
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                ret = " " + tmp + ret;
                tmp = "";

            } else {
                tmp += str[i];
            }
        }
        if (tmp.size())
            ret = tmp + ret;
        return ret;
    }
};