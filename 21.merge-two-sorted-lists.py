#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#
# https://leetcode.com/problems/merge-two-sorted-lists/description/
#
# algorithms
# Easy (46.40%)
# Total Accepted:    557.8K
# Total Submissions: 1.2M
# Testcase Example:  '[1,2,4]\n[1,3,4]'
#
# Merge two sorted linked lists and return it as a new list. The new list
# should be made by splicing together the nodes of the first two lists.
# 
# Example:
# 
# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4
# 
# 
#
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        """递归
        """
        if not l1:
            return l2
        if not l2:
            return l1
        # 用于保存新的链表
        if l1.val < l2.val:
            new_list = l1
            new_list.next = self.mergeTwoLists(l1.next, l2)
        else:
            new_list = l2
            new_list.next = self.mergeTwoLists(l2.next, l1)
        return new_list


