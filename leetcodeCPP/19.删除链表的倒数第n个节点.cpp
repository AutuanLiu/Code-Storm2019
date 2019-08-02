/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.80%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    59.1K
 * Total Submissions: 169.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // 快慢指针
        ListNode *fast = head, *slow = head;
        while (n) {
            fast = fast->next;
            n--;
        }
        // 此时要删除的是链表的头结点
        if (fast == nullptr)
            return head->next;

        // 要删除的是链表的第2个节点到最后的位置处的节点
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // 找到了要删除的节点的前一个节点
        slow->next = slow->next->next;
        return head;
    }
};
