class Solution
{
  public:
    void push(int value)
    {
        stk.push(value);
        if (stk_min.empty())
            stk_min.push(value);
        else if (value <= stk_min.top())
            stk_min.push(value);
    }
    void pop()
    {
        //stk.pop();
        if (stk.top() == stk_min.top())
            stk_min.pop();
        stk.pop();
    }
    int top()
    {
        return stk.top();
    }
    int min()
    {
        return stk_min.top();
    }

  private:
    stack<int> stk;
    stack<int> stk_min;
};

class Solution
{
  public:
    void push(int value)
    {
        st.push(value);
        if (smin.empty())
            smin.push(value);
        if (smin.top() > value)
            smin.push(value);
    }
    void pop()
    {
        if (smin.top() == st.top())
            smin.pop();
        st.pop();
    }
    int top()
    {
        return st.top();
    }
    int min()
    {
        return smin.top();
    }

  private:
    stack<int> st;
    stack<int> smin;
};

class Solution
{
  public:
    void push(int value)
    {
        StackInt.push(value);
        if (StackMin.empty())
            StackMin.push(value);
        else if (StackMin.top() < value)
            StackMin.push(StackMin.top());
        else
            StackMin.push(value);
    }
    void pop()
    {
        if (!StackInt.empty())
        {
            StackInt.pop();
            StackMin.pop();
        }
    }
    int top()
    {
        return StackInt.top();
    }
    int min()
    {
        return StackMin.top();
    }

  private:
    stack<int> StackInt;
    stack<int> StackMin;
};
