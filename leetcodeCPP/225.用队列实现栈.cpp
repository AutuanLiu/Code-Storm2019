/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queue1s/description/
 *
 * algorithms
 * Easy (59.82%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 26.7K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用队列实现栈的下列操作：
 * 
 * 
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 
 * 注意:
 * 
 * 
 * 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty
 * 这些操作是合法的。
 * 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 * 
 * 
 */
//思路就是每push一个新元素到队尾，队列自动循环将队首的元素pop并重新push到队尾，直到把新元素顶到队首
class MyStack {
public:
    queue<int> queue1;
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        queue1.push(x);
        int n = queue1.size();
        // 除了当前元素 其余入队列
        for (int i = 1; i < n; i++) {
            queue1.push(queue1.front());
            queue1.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int ret = queue1.front();
        queue1.pop();
        return ret;
    }

    /** Get the top element. */
    int top()
    {
        return queue1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
