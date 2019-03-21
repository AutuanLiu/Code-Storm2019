#
# @lc app=leetcode id=386 lang=python3
#
# [386] Lexicographical Numbers
#
# https://leetcode.com/problems/lexicographical-numbers/description/
#
# algorithms
# Medium (45.00%)
# Total Accepted:    37.7K
# Total Submissions: 83.7K
# Testcase Example:  '13'
#
# Given an integer n, return 1 - n in lexicographical order.
#
# For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
#
# Please optimize your algorithm to use less time and space. The input size may
# be as large as 5,000,000.
#
#
# DFS
# class Solution:
#     def lexicalOrder(self, n: int) -> List[int]:
#         return list(map(int, sorted(map(str, range(1, n + 1)))))


class Solution:
    def __init__(self):
        self.res = []

    def lexicalOrder(self, n: int) -> List[int]:
        # 第一层 1-9
        for i in range(1, 10):
            if i <= n:
                self.res.append(i)
                self.dfs(n, i * 10)    # 下一层从 10*i 开始 DFS
            else:
                break    # 只有第一层
        return len(self.res)

    def dfs(self, n, y):
        """DFS

        Args:
            n (int): 数组数据最大值
            y (int): DFS开始的节点
        """

        for i in range(10):
            # 每个根节点下是10个数，十叉树
            tmp = y + i    # 当前数值
            if tmp <= n:
                self.res.append(tmp)
                self.dfs(n, tmp * 10)
            else:
                break    # 已经达到最大值

