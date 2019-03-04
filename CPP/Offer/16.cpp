class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {

        ListNode *p1, *p2, *pre1, *p3;
        pre1 = p1 = pHead1;
        p2 = pHead2;
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

class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        else if (pHead2 == NULL)
            return pHead1;

        ListNode *newhead = NULL;

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

class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        ListNode *mergeList = NULL;
        if (pHead1->val < pHead2->val)
        {
            mergeList = pHead1;
            mergeList->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            mergeList = pHead2;
            mergeList->next = Merge(pHead1, pHead2->next);
        }
        return mergeList;
    }
};
