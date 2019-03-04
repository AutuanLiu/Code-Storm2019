class Solution
{
  public:
    int cou = 0;
    void push(int node)
    {
        stack1.push_back(node);
        stack2.push_back(cou++);
    }

    int pop()
    {
        int i = 0;
        while (stack2[i] == -1)
        {
            i++;
        }
        stack2[i] = -1;
        return stack1[i];
    }

  private:
    vector<int> stack1; //存数
    vector<int> stack2; //地址
};
