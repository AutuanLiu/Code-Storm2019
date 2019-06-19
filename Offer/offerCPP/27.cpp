class Solution
{
  public:
    vector<string> result;   // 保存结果
    vector<string> Permutation(string str)
    {
        if (str.length() == 0)
            return result;
        Permutation1(str, 0);
        // 结果是有序的，所以这里要对结果进行排序
        sort(result.begin(), result.end());
        return result;
    }

    void Permutation1(string str, int begin)
    {
        if (begin == str.length())
        {
            result.push_back(str);
            return;
        }


        for (int i = begin; str[i] != '\0'; i++)
        {
            // 排除重复元素
            if (i != begin && str[begin] == str[i])
                continue;
            swap(str[begin], str[i]);
            Permutation1(str, begin + 1);
            swap(str[begin], str[i]);
        }
    }
};

class Solution
{
  public:
    vector<string> result;
    vector<string> Permutation(string str)
    {
        if (str.empty())
            return result;
        permution(str, 0);
        sort(result.begin(), result.end());
        // 排除重复的元素
        for (auto it = result.begin(); (it + 1) != result.end();)
        {
            if (*it == *(it + 1))
                it = result.erase(it);
            else
                it++;
        }
        return result;
    }

    void permution(string str, int i)
    {
        if (i == str.length() - 1)
            result.push_back(str);
        for (int j = i; j < str.length(); j++)
        {
            swap(str[j], str[i]);
            permution(str, i + 1);
            swap(str[j], str[i]);
        }
    }
};
