// 字符串的排列.cpp
class Solution {
public:
    vector<string> ret; // 保存结果
    vector<string> Permutation(string str)
    {
        int n = str.length();
        if (n == 0)
            return ret;
        // 先排序使得重复的字母在一起
        // sort(str.begin(), str.end());
        Permutation1(str, 0, n);
        // 结果是有序的，所以这里要对结果进行排序
        sort(ret.begin(), ret.end());
        return ret;
    }

    void Permutation1(string str, int begin, int n)
    {
        if (begin == n) {
            ret.push_back(str);
            return;
        }

        for (int i = begin; i < n; i++) {
            // 排除重复元素
            if (i != begin && str[i] == str[begin])
                continue;
            swap(str[begin], str[i]);
            Permutation1(str, begin + 1, n);
            swap(str[begin], str[i]); // 回溯
        }
        return;
    }
};

class Solution {
public:
    vector<string> ret;
    vector<string> Permutation(string str)
    {
        if (str.empty())
            return ret;
        permution(str, 0);
        sort(ret.begin(), ret.end());
        // 排除重复的元素
        for (auto it = ret.begin(); (it + 1) != ret.end();) {
            if (*it == *(it + 1))
                it = ret.erase(it);
            else
                it++;
        }
        return ret;
    }

    void permution(string str, int i)
    {
        if (i == str.length() - 1)
            ret.push_back(str);
        for (int j = i; j < str.length(); j++) {
            swap(str[j], str[i]);
            permution(str, i + 1);
            swap(str[j], str[i]);
        }
    }
};
