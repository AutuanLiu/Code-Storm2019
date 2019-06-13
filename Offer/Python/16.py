class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 递归
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        if pHead1 == None:
            return pHead2
        if pHead2 == None:
            return pHead1

        newHead = None

        if pHead1.val < pHead2.val:
            newHead = pHead1
            newHead.next = self.Merge(pHead1.next, pHead2)
        else:
            newHead = pHead2
            newHead.next = self.Merge(pHead1, pHead2.next)
        return newHead


# 非递归
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        if pHead1 == None:
            return pHead2
        if pHead2 == None:
            return pHead1
        newHead, newCur = None, None
        # 先找到新链表的头结点
        if (pHead1.val < pHead2.val):
            newHead = pHead1
            pHead1 = pHead1.next
        else:
            newHead = pHead2
            pHead2 = pHead2.next
        # 新链表的当前位置, 首先指向头结点
        newCur = newHead
        while (pHead1 and pHead2):
            if pHead1.val < pHead2.val:
                newCur.next = pHead1
                pHead1 = pHead1.next
            else:
                newCur.next = pHead2
                pHead2 = pHead2.next
            newCur = newCur.next    # 新链表向前移动

        # 当两个链表不一样长
        if pHead1:
            newCur.next = pHead1
        if pHead2:
            newCur.next = pHead2
        return newHead
