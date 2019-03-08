class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() == 0 || pushV.size() != popV.size())
            return false;

        for (int i = 0, index = 0; i < pushV.size(); i++)
        {
            s.push(pushV[i]);  // 压栈

            while (!s.empty() && s.top() == popV[index])
            {
                s.pop();
                index++;
            }
        }

        return s.empty();
    }

  private:
    stack<int> s; // 辅助栈
};

class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        vector<int> temp; //辅助数组
        for (int i = 0, j = 0; i < pushV.size();)
        {
            temp.push_back(pushV[i++]);
            while (j < popV.size() && temp.back() == popV[j])
            {
                temp.pop_back();
                j++;
            }
        }
        return temp.empty();
    }
};
