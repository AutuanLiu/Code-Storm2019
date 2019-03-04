class Solution
{
  public:
    ListNode *ReverseList(ListNode *pHead)
    {

        if (pHead == NULL)
            return pHead;
        ListNode *pre = NULL;
        ListNode *cur = pHead;
        ListNode *nxt = NULL;
        ListNode *res = NULL;
        while (cur != NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            if (nxt == NULL)
            {
                break;
            }
            pre = cur;
            cur = nxt;
        }
        return cur;
    }
};

class Solution
{
  public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        ListNode *pNode = pHead;
        ListNode *pREHead = nullptr;
        ListNode *pPre = nullptr;

        while (pNode != nullptr)
        {
            ListNode *pNext = pNode->next;
            if (pNext == nullptr)
                pREHead = pNode;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        return pREHead;
    }
};
