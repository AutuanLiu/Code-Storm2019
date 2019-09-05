// 反转链表
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
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
