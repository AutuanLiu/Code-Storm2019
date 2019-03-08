// 长度不一致
class Solution
{
  public:
    void push(int value)
    {
        stk.push(value);
        if (stk_min.empty())
            stk_min.push(value);  // sth_min 是空的，那么当前值就是最小值
        else if (value <= stk_min.top())
            stk_min.push(value);
    }

    void pop()
    {
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


// 长度一致
class Solution
{
  public:
    void push(int value)
    {
        StackInt.push(value);  // push 数据栈
        if (StackMin.empty())
            StackMin.push(value);  // 如果最小值栈为空，当前值就是最小值
        else if (StackMin.top() < value)
            // 当前值大，最小值不变
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
    // 辅助栈
    stack<int> StackInt;
    stack<int> StackMin;
};
