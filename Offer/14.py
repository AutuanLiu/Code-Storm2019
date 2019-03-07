# 双指针，快慢
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        if head == None or k == 0:
            return None
        kth, end, cnt = None, head, 1
        while end != None:
            if cnt == k:
                kth = head
            elif cnt > k:
                kth = kth.next
            end = end.next
            cnt += 1
        return kth
