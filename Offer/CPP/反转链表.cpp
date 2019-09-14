// 反转链表
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

// 前向插入的思路
// 涉及双向操作的时候，注意避免链表的断裂
class Solution {
public:
    ListNode* ReverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* p = head; // 当前节点
        ListNode* ret = nullptr; // 新链表的头结点

        while (p != nullptr) {
            ListNode* q = p->next; // 保存下一个节点防止断裂

            p->next = ret; // 前向插入
            ret = p;

            p = q; // 继续从保存的位置开始
        }
        return ret;
    }
};

// 递归写法
class Solution {
public:
    ListNode* ReverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* ret = ReverseList(head->next); // 先翻转后面的链表
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
};

// 这题目也可以借助一个栈
// 遍历链表把每个节点都入栈之后按照出栈的顺序构造新的链表即可
class Solution {
public:
    ListNode* ReverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* ret; // 新链表的头结点
        stack<ListNode*> sk;

        while (head->next != nullptr) {
            sk.push(head);
            head = head->next;
        }
        ret = head;
        while (!sk.empty()) {
            head->next = sk.top(); // 连接栈顶元素
            sk.pop(); // 出栈
            head = head->next;
        }
        head->next = nullptr;
        return ret;
    }
};