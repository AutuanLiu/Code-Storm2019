/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (62.23%)
 * Likes:    471
 * Dislikes: 0
 * Total Accepted:    68.4K
 * Total Submissions: 109.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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

// 迭代 头插法
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head)
//     {
//         ListNode* ret = nullptr;
//         ListNode* p = head;
//         while (p) {
//             ListNode* tmp = p;
//             p = p->next;
//             tmp->next = ret;
//             ret = tmp;
//         }
//         return ret;
//     }
// };

// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        // 递归出口
        if (!head || !head->next)
            return head;
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
};
