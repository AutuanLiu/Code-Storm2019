# 2. Add Two Numbers
# Runtime: 108 ms, faster than 71.41% of Python3 online submissions for Add Two Numbers.
# Memory Usage: 13.2 MB, less than 5.21% of Python3 online submissions for Add Two Numbers.
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = cur = ListNode(0)  # 构造结果与当前指针
        carry = 0  # 存储进位
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            cur.next = ListNode(carry % 10)
            cur = cur.next
            carry //= 10
        return dummy.next

# Runtime: 116 ms, faster than 52.86% of Python3 online submissions for Add Two Numbers.
# Memory Usage: 13.3 MB, less than 5.21% of Python3 online submissions for Add Two Numbers.

class Solution:
    def addTwoNumbers(self, l1, l2):
        if not l1 and not l2:
            return
        elif not (l1 and l2):
            return l1 or l2
        else:
            if l1.val + l2.val < 10:
                l3 = ListNode(l1.val + l2.val)
                l3.next = self.addTwoNumbers(l1.next, l2.next)
            else:
                l3 = ListNode(l1.val + l2.val - 10)
                l3.next = self.addTwoNumbers(l1.next, self.addTwoNumbers(l2.next, ListNode(1)))
        return l3