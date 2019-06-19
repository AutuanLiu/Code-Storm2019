class Solution
{
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
            return NULL;
        set<int> myset;

        ListNode *p1 = pHead1;
        while (p1)
        {
            myset.insert(p1->val);
            p1 = p1->next;
        }

        ListNode *p2 = pHead2;
        while (p2)
        {
            if (find(myset.begin(), myset.end(), p2->val) != myset.end())
                return p2;

            p2 = p2->next;
        }

        return NULL;
    }
};

class Solution
{
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        int len1 = 0, len2 = 0, diff = 0;
        while (p1 != NULL)
        {
            p1 = p1->next;
            len1++;
        }
        while (p2 != NULL)
        {
            p2 = p2->next;
            len2++;
        }
        if (len1 > len2)
        {
            diff = len1 - len2;
            p1 = pHead1;
            p2 = pHead2;
        }
        else
        {
            diff = len2 - len1;
            p1 = pHead2;
            p2 = pHead1;
        }
        for (int i = 0; i < diff; i++)
        {
            p1 = p1->next;
        }
        while (p1 != NULL && p2 != NULL)
        {
            if (p1 == p2)
                break;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

class Solution
{
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int length1 = GetLength(pHead1);
        int length2 = GetLength(pHead2);
        ListNode *pNode1 = pHead1;
        ListNode *pNode2 = pHead2;

        int lengthDif = 0;
        if (length1 >= length2)
        {
            lengthDif = length1 - length2;
            for (int i = 0; i < lengthDif; i++)
                pNode1 = pNode1->next;
        }
        if (length1 < length2)
        {
            lengthDif = length2 - length1;
            for (int i = 0; i < lengthDif; i++)
                pNode2 = pNode2->next;
        }

        while ((pNode1 != nullptr) && (pNode2 != nullptr) && (pNode1->val != pNode2->val))
        {
            //  if(pNode1->val==pNode2->val)
            //     return pNode1;
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        ListNode *pCommonNode = pNode1;
        return pCommonNode;
        //      return nullptr;
    }
    int GetLength(ListNode *pHead)
    {
        ListNode *pNode = pHead;
        int length = 0;
        while (pNode != nullptr)
        {
            length++;
            pNode = pNode->next;
        }
        return length;
    }
};
