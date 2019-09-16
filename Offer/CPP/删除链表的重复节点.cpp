// 删除链表的重复节点
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// 首先是一个排序链表
// 那么重复的节点一定都在一起
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head)
    {
        if (head == nullptr)
            return head;
        ListNode *pre = nullptr, *p = head, *q = nullptr;

        while (p != nullptr) {
            //当前结点p，，与它下一个结点p->next的val相同，说明要删掉有这个val的所有结点
            if (p->next != nullptr && p->next->val == p->val) {
                q = p->next;
                //找到q，它指向最后一个与p->val相同的结点，那p到q都是要删除的
                while (q != nullptr && q->next != nullptr && q->next->val == p->val) {
                    q = q->next;
                }
                // 如果p指向链表中第一个元素要删除p到q, 将指向链表第一个元素的指针pHead指向q->next
                if (p == head) {
                    head = q->next;
                } else {
                    pre->next = q->next;
                }
                //当前处理的p要向链表尾部移动
                p = q->next;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};

// leetcode26
// 快慢指针
// 链表1->2->3->3->4->4->5 处理后为 1->2->3->4->5
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head)
    {
        if (head == nullptr)
            return head;
        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 一定要断开后续连接  表示结束
        slow->next = nullptr;
        return head;
    }
};