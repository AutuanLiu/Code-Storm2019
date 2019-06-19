struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *p1 = pHead1, *p2 = pHead2, *pre1 = pHead1, *p3;
        while (p1 && p2)
        {
            if (p1->val > p2->val)
            {
                pre1->next = p2;
                p3 = p2->next;
                p2->next = p1;
                p2 = p3;
            }
            pre1 = p1;
            p1 = p1->next;
        }
        if (p2)
            pre1->next = p2;

        return pHead1;
    }
};


// 递归
class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        else if (pHead2 == nullptr)
            return pHead1;

        ListNode *newhead = nullptr;

        if (pHead1->val < pHead2->val)
        {
            newhead = pHead1;
            newhead->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            newhead = pHead2;
            newhead->next = Merge(pHead1, pHead2->next);
        }
        return newhead;
    }
};

// 非递归递归
class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        // 特殊情况处理
        if (pHead1 == nullptr)
            return pHead2;
        else if (pHead2 == nullptr)
            return pHead1;

        ListNode *newHead = nullptr, *newCur = nullptr;
        // 先找到新链表的头结点
        if (pHead1->val < pHead2->val)
        {
            newHead = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            newHead = pHead2;
            pHead2 = pHead2->next;
        }
        // 新链表的当前位置, 首先指向头结点
        newCur = newHead;
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                newCur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                newCur->next = pHead2;
                pHead2 = pHead2->next;
            }
            newCur = newCur->next;  // 新链表向前移动
        }
        // 当两个链表不一样长
        if (pHead1)
            newCur->next = pHead1;
        if (pHead2)
            newCur->next = pHead2;
        return newHead;
    }
};
