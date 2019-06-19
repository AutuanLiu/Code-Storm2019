#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        #base case, look k steps forward to see if the block needs to be reversed
        #if the length is less than k, do nothing, return the current head

        nextHead = head
        for i in range(0, k):
            if (nextHead == None):
                return head
            nextHead = nextHead.next

            #the length is greater than k, reverse the first k

        prev = None
        connect = cur = head
        for i in range(0, k):
            cur.next, cur, prev = prev, cur.next, cur

        #recursively call on rest of the list then connect two parts

        connect.next = self.reverseKGroup(nextHead, k)

        return prev
