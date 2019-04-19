#
# @lc app=leetcode id=147 lang=python3
#
# [147] Insertion Sort List
#
# https://leetcode.com/problems/insertion-sort-list/description/
#
# algorithms
# Medium (36.70%)
# Total Accepted:    145.9K
# Total Submissions: 395.8K
# Testcase Example:  '[4,2,1,3]'
#
# Sort a linked list using insertion sort.
#
#
#
#
#
# A graphical example of insertion sort. The partial sorted list (black)
# initially contains only the first element in the list.
# With each iteration one element (red) is removed from the input data and
# inserted in-place into the sorted list
#
#
#
#
#
# Algorithm of Insertion Sort:
#
#
# Insertion sort iterates, consuming one input element each repetition, and
# growing a sorted output list.
# At each iteration, insertion sort removes one element from the input data,
# finds the location it belongs within the sorted list, and inserts it
# there.
# It repeats until no input elements remain.
#
#
#
# Example 1:
#
#
# Input: 4->2->1->3
# Output: 1->2->3->4
#
#
# Example 2:
#
#
# Input: -1->5->3->4->0
# Output: -1->0->3->4->5
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        # 以下处理最少有两个节点的情况
        p = ret = ListNode(0)  # 初始化一个链表，用于排序结果
        cur = ret.next = head  # 用于遍历待排序的链表
        while cur and cur.next:
            next_val = cur.next.val
            if cur.val <= next_val:
                cur = cur.next
                continue

            if p.next.val > next_val:
                p = ret

            while p.next.val <= next_val:
                p = p.next

            p.next, cur.next.next, cur.next = cur.next, p.next, cur.next.next
        return ret.next
