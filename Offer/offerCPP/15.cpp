struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 前向插入的思路
// 涉及双向操作的时候，注意避免链表的断裂
class Solution
{
  public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;

        ListNode* pNode = pHead;       // 当前节点
        ListNode* pReHead = nullptr;   // 新链表的头结点

        while (pNode != nullptr)
        {
            ListNode* pNext = pNode->next;  // 保存下一个节点
            pNode->next = pReHead;
            pReHead = pNode;
            pNode = pNext;
        }
        return pReHead;
    }
};
