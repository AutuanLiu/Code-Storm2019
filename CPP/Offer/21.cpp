class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() == 0)
            return false;

        int index = 0; //popV的下标
        stack<int> s;
        //
        for (int i = 0; i < pushV.size(); i++)
        {
            s.push(pushV[i]);

            while (s.empty() == false && s.top() == popV[index] && index < popV.size())
            {
                s.pop();
                index++;
            }
        }
        //
        if (s.empty() == true)
            return true;
        else
            return false;
    }
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

class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> st;
        int id = 0;
        for (int i = 0; i < popV.size(); ++i)
        {
            while (st.empty() || st.top() != popV[i])
            {
                st.push(pushV[id++]);
                if (id > pushV.size())
                {
                    return false;
                }
            }
            st.pop();
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
