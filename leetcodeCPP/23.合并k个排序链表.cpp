/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (46.50%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 58.1K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int ln = lists.size();
//         if (ln == 1) return lists[0];
//         if (ln == 0) return nullptr;
//         ListNode* ret = lists[0];
//         for (int i = 1; i < ln; i++)
//             ret = merge2List(ret, lists[i]);
//         return ret;
//     }

//     ListNode* merge2List(ListNode* l1, ListNode* l2) {
//         if (l1 == nullptr)
//             return l2;
//         else if (l2 == nullptr)
//             return l1;
//         else {
//             if (l1->val < l2->val) {
//                 // 在自身基础上操作（原地操作）
//                 l1->next = merge2List(l1->next, l2);
//                 return l1;
//             } else {
//                 l2->next = merge2List(l1, l2->next);
//                 return l2;
//             }
//         }
//     }
// };

// 非递归
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*> &lists)
//     {
//         int ln = lists.size();
//         if (ln == 1) return lists[0];
//         if (ln == 0) return nullptr;
//         ListNode* ret = lists[0];
//         for (int i = 1; i < ln; i++)
//             ret = merge2List(ret, lists[i]);
//         return ret;
//     }

//     ListNode* merge2List(ListNode* l1, ListNode* l2) {
//         ListNode* ret = new ListNode(0);
//         ListNode* cur = ret;
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
//         cur->next = l1 ? l1 : l2;
//         return ret->next;
//     }
// };

// 两两合并加归并
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int ln = lists.size();
        if (ln == 1)
            return lists[0];
        if (ln == 0)
            return nullptr;
        return merge(lists, 0, ln - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);
        return merge2List(l1, l2);
    }

    ListNode* merge2List(ListNode* l1, ListNode* l2)
    {
        ListNode* ret = new ListNode(0);
        ListNode* cur = ret;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return ret->next;
    }
};
