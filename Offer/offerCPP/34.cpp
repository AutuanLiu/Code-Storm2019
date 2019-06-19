class Solution
{
  public:
    int FirstNotRepeatingChar(string str)
    {
        int len = str.size();
        if (len <= 0)
            return -1;
        int cnt[100] = {0};
        int i, res = -1;
        for (i = 0; i < len; i++)
        {
            cnt[str[i] - 'A']++;
        }
        for (i = 0; i < len; i++)
        {
            if (cnt[str[i] - 'A'] == 1)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};

class Solution
{
  public:
    int FirstNotRepeatingChar(string str)
    {
        if (str.size() == 0)
            return -1;
        char ch[256] = {0};
        for (int i = 0; i < str.size(); i++)
            ch[str[i]]++;
        for (int i = 0; i < str.size(); i++)
            if (ch[str[i]] == 1)
                return i;
        return 0;
    }
};

class Solution
{
  public:
    int FirstNotRepeatingChar(string str)
    {
        if (str.empty())
            return -1;
        map<char, int> dict;
        for (string::size_type i = 0; i < str.size(); ++i)
        {
            ++dict[str[i]];
        }
        string::size_type pos = 0;
        for (string::size_type i = 0; i < str.size(); ++i)
        {
            if (dict[str[i]] == 1)
            {
                pos = i;
                break;
            }
        }
        return pos;
    }
};
