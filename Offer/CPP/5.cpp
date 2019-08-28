class Solution {
public:
    void push(int node)
    {
        stack1.push(node); // 在 stack1 push即相当于队尾插入
    }

    int pop()
    {
        // 从 stack2 出栈即相当于队首出队
        if (stack2.empty() && !stack1.empty()) {
            // 如果 stack2 是空的话，就将 stack1 的所有元素压入 stack2 中
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // if (stack2.empty())
        // 	throw new exception("queue is empty");  // retrun 0
        int tmp = stack2.top(); // 取栈顶元素
        stack2.pop(); // 注意顺序
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
