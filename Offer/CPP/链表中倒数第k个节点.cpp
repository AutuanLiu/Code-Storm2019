// 链表中倒数第k个节点.cpp
// 双指针，注意鲁棒性、k是无符号型
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}

class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == nullptr || k == 0)
            return nullptr;
        ListNode *kth = nullptr, *end = pListHead;
        unsigned int count = 1;  // 用于统计， 和 k 一致
        while (end != nullptr)
        {
            if (count == k)
                kth = pListHead;
            else if (count > k)
                kth = kth->next;  // 同步移动
            end = end->next;
            count++;
        }
        return kth;  // 当小于 k 时返回 nullptr
    }
};

class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == nullptr || k == 0)
            return nullptr;
        ListNode *kth = nullptr, *end = pListHead;
        for (unsigned int i = 0; i < k - 1; i++)
        {
            if (end->next != nullptr)
                end = end->next;
            else
                return nullptr;
        }
        kth = pListHead;
        while (end->next != nullptr)
        {
            end = end->next;
            kth = kth->next;
        }
        return kth; // 当小于 k 时返回 nullptr
    }
};

// 两遍遍历，找出 n-k+1
class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        ListNode *point = pListHead;
        unsigned int pos = 0;
        unsigned int size = 1;
        while (point)
        {
            point = point->next;
            size++;
        }
        if (k >= size)
            return point;
        pos = size - k + 1;
        unsigned int n = 1;
        point = pListHead;
        while (point && n < pos - 1)
        {
            point = point->next;
            n++;
        }
        return point;
    }
};
