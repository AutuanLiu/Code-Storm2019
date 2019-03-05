/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

// 借助栈来实现
class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> result;
        stack<int> stk;
        ListNode *p = head;
        while (p != nullptr)
        {
            stk.push(p -> val);
            p = p -> next;
        }
        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};

// 直接使用 vector 的 insert 方法，每次在开始处插入元素
class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> array;
        if (head != nullptr)
        {
            // 在 array 开始处插入元素
            array.insert(array.begin(), head -> val);
            // 从下一个开始
            while (head -> next != nullptr)
            {
                array.insert(array.begin(), head -> next -> val);
                head = head -> next;
            }
        }
        return array;
    }
};
