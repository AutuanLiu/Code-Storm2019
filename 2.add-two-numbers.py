#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#
# 链表一定要记得指针操作
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution1:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = ret = ListNode(None)
        carry = 0
        # 要考虑最高位进位
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            cur.next = ListNode(carry % 10)
            carry = carry // 10
            cur = cur.next
        return ret.next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = ret = ListNode(None)
        carry = 0
        # 要考虑最高位进位 重点注意
        while l1 or l2 or carry:
            a, b = 0, 0
            if l1:
                a = l1.val
                l1 = l1.next
            if l2:
                b = l2.val
                l2 = l2.next
            c = a + b + carry
            cur.next = ListNode(c % 10)
            carry = c // 10
            cur = cur.next
        return ret.next
