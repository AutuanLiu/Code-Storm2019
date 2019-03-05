class Solution
{
  public:
    vector<string> result;
    vector<string> Permutation(string str)
    {
        if (str.length() == 0)
        {
            return result;
        }
        Permutation1(str, 0);
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
    vector<string> Permutation(string str)
    {
        vector<string> result;
        int i = 0;
        if (str.empty())
        {
            return result;
        }
        permution(str, i, result);
        sort(result.begin(), result.end());
        vector<string>::iterator it;
        for (it = result.begin(); (it + 1) != result.end();)
        {
            if (*it == *(it + 1))
            {
                it = result.erase(it);
            }
            else
                it++;
        }
        return result;
    }
    void permution(string str, int i, vector<string> &result)
    {
        if (i == str.length() - 1)
        {
            result.push_back(str);
        }
        for (int j = i; j < str.length(); j++)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            permution(str, i + 1, result);
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
};
