class Solution
{
  public:
    string PrintMinNumber(vector<int> numbers)
    {
        int len = numbers.size();
        if (len == 0)
            return "";
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for (int i = 0; i < len; i++)
        {
            res += to_string(numbers[i]);
        }
        return res;
    }
    static bool cmp(int a, int b)
    {
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};

class Solution
{
  public:
    string PrintMinNumber(vector<int> numbers)
    {
        string ret;
        vector<string> numbers_str;
        string t;
        for (int i = 0; i < numbers.size(); ++i)
            numbers_str.push_back(to_string(numbers[i]));

        for (int i = 0; i < numbers_str.size(); i++)
        {
            for (int j = i + 1; j < numbers_str.size(); j++)
            {
                string a = (numbers_str[i] + numbers_str[j]);
                string b = (numbers_str[j] + numbers_str[i]);
                if (a > b)
                {
                    t = numbers_str[i];
                    numbers_str[i] = numbers_str[j];
                    numbers_str[j] = t;
                }
            }
        }

        for (int i = 0; i < numbers_str.size(); ++i)
            ret += numbers_str[i];
        return ret;
        /*
        string ret;
        vector<string> numbers_str;
        for(int i = 0; i < numbers.size(); ++i)
            numbers_str.push_back(to_string(numbers[i]));
        sort(numbers_str.begin(), numbers_str.end(), MyCompare);
        for(int i = 0; i < numbers_str.size(); ++i)
            ret += numbers_str[i];
        return ret;
    }
private:
    static bool MyCompare(const string &str1, const string &str2){
        return str1 + str2 < str2 + str1;
    }
    */
    }
};

class Solution
{
  public:
    string PrintMinNumber(vector<int> numbers)
    {
        if (numbers.empty())
            return "";

        vector<string> str;
        str.reserve(numbers.size());

        for (auto c : numbers)
            str.push_back(std::to_string(c));

        std::sort(str.begin(), str.end(), [](string a, string b) { return a + b < b + a; });

        string result;
        for (auto s : str)
            result += s;

        return result;
    }
};
