class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        if pHead == None or pHead.next == None:
            return pHead
        pNode, pReHead = pHead, None
        while pNode != None:
            pNext = pNode.next
            pNode.next = pReHead
            pReHead = pNode
            pNode = pNext
        return pReHead
