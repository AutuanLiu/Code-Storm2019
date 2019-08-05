/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (55.08%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    77.5K
 * Total Submissions: 140.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
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

// 迭代
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* ret = new ListNode(0);
//         ListNode *cur = ret;
//         while (l1 && l2) {
//             if (l1->val < l2->val) {
//                 cur->next = l1;
//                 l1 = l1->next;
//             } else {
//                 cur->next = l2;
//                 l2 = l2->next;
//             }
//             cur = cur->next;
//         }

//         // 将剩余的链表直接连接即可
//         cur->next = l1 ? l1 : l2;
//         // if (l1)
//         //     cur->next = l1;
//         // if (l2)
//         //     cur->next = l2;
//         return ret->next;
//     }
// };

// 递归 归并排序
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
        else {
            if (l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
};
