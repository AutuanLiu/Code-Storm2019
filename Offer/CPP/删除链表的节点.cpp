// 删除链表的节点
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// 把要删除的节点的下一个数值复制给他
// 然后把它指向下下一个
// 在分配空间给指针之后，一定要用NULL来判断一下是否成功了。然后在删除这个指针的时候，也要用NULL来赋给指针，杜绝成为野指针！
class Solution {
public:
    void deleteNode(ListNode* head, ListNode* pToDelete)
    {
        if (head == nullptr || pToDelete == nullptr)
            return;

        // 如果要删除的节点不是尾结点
        if (pToDelete->next != nullptr) {
            pToDelete->val = pToDelete->next->val;
            pToDelete->next = pToDelete->next->next;
        }

        // 链表只有一个节点，要删除头结点
        else if (head->next == pToDelete) {
            delete pToDelete;
            pToDelete = nullptr; // 删除指针后要赋空值
            head = nullptr; // 头指针不存在也为空指针
        }

        // 存在多个节点 要删除尾结点
        else {
            ListNode* p = head;
            while (p->Next != pToDelete) {
                p = p->Next;
            }

            p->Next = nullptr;
            delete pToDelete;
            pToDelete = nullptr;
        }
    }
};
