class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *p, unsigned int k)
    {
        //if(!p) return nullptr;
        auto p1 = p;
        for (int i = 0; i != k; ++i)
            if (!p1)
                return nullptr;
            else
                p1 = p1->next;
        while (p1)
        {
            p1 = p1->next;
            p = p->next;
        }
        return p;
    }
};

class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == NULL)
            return pListHead;
        if (k == 0)
            return NULL;
        ListNode *kth = NULL, *end = pListHead;
        int count = 1;
        while (end != NULL)
        {
            if (count++ == k)
            {
                kth = pListHead;
            }
            else if (count > k)
            {
                kth = kth->next;
            }
            end = end->next;
        }
        return kth;
    }
};

class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        ListNode *point = pListHead;
        int pos = 0;
        int size = 1;
        while (point)
        {
            point = point->next;
            size++;
        }
        if (k >= size)
        {
            return point;
        }
        pos = size - k + 1;
        int n = 1;
        point = pListHead;
        while (point && n < pos - 1)
        {
            point = point->next;
            n++;
        }
        return point;
    }
};
