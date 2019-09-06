// 栈的压入弹出序列.cpp
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int m = pushV.size(), n = popV.size();
        if (m == 0 || m != n)
            return false;

        stack<int> s; // 辅助栈用于模拟进出栈
        for (int i = 0, j = 0; i < m; i++) {
            s.push(pushV[i]); // 压栈

            // 不断压栈直到栈顶元素等于出栈元素的时候就出栈继续判断下一个
            while (!s.empty() && s.top() == popV[j]) {
                s.pop();
                j++;
            }
        }

        return s.empty();
    }
};

// 和上述方法是一样的 区别只在于实现方式
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int m = pushV.size(), n = popV.size();
        if (m == 0 || m != n)
            return false;

        vector<int> temp; //辅助数组
        for (int i = 0, j = 0; i < m;) {
            temp.push_back(pushV[i++]);
            while (j < popV.size() && temp.back() == popV[j]) {
                temp.pop_back();
                j++;
            }
        }
        return temp.empty();
    }
};
