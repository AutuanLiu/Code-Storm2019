/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (61.32%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 30.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
// 归并排序
class Solution {
public:
    // ListNode* mergeSorted2List(ListNode* l1, ListNode* l2)
    // {
    //     // 递归出口
    //     if (l1 == nullptr) return l2;
    //     if (l2 == nullptr) return l1;
    //     if (l1->val < l2->val) {
    //         l1->next = mergeSorted2List(l1->next, l2);
    //         return l1;
    //     } else {
    //         l2->next = mergeSorted2List(l1, l2->next);
    //         return l2;
    //     }
    // }

    ListNode* cut(ListNode* head, int n)
    {
        ListNode* p = head;
        while (--n && p) {
            p = p->next;
        }

        if (!p)
            return nullptr;

        ListNode* next = p->next;
        p->next = nullptr;
        return next;
    }

    // 合并两个有序的链表
    ListNode* mergeSorted2List(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
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
        return dummy->next;
    }

    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr)
            return head;
        // 计算链表的长度
        int n = 0;
        ListNode *p = head, *ret = new ListNode(0);
        ret->next = head;
        while (p) {
            p = p->next;
            n++;
        }

        // 先对链表分段 然后分组（2个为一组）最组内链表进行排序
        // 当段长度为1时，认为是有序的
        for (int seg = 1; seg < n; seg <<= 1) {
            ListNode* cur = ret->next;
            ListNode* tail = ret;

            while (cur) {
                ListNode* left = cur;
                ListNode* right = cut(left, seg);
                cur = cut(right, seg);

                tail->next = mergeSorted2List(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return ret->next;
    }
};
