// 两个链表的第一个公共节点.cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1 || !pHead2)
            return nullptr;
        ListNode *p1 = pHead1, *p2 = pHead2, *longer, *shorter;
        int cnt = 0;
        while (p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1) {
            longer = pHead1;
            shorter = pHead2;
        } else {
            longer = pHead2;
            shorter = pHead1;
        }
        ListNode* p = p1 ? p1 : p2;
        while (p) {
            p = p->next;
            cnt++;
        }
        while (cnt) {
            longer = longer->next;
            cnt--;
        }
        while (longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }
        return shorter;
    }
};
