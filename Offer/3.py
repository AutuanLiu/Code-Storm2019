class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 列表可以理解为栈
class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        res = []
        while listNode:
            res.append(listNode.val)
            listNode = listNode.next
        return res[::-1]


# 使用列表的插入操作
class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        res = []
        while listNode:
            res.insert(0, listNode.val)
            listNode = listNode.next
        return res
