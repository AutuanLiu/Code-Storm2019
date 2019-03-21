#
# @lc app=leetcode id=310 lang=python3
#
# [310] Minimum Height Trees
#
# https://leetcode.com/problems/minimum-height-trees/description/
#
# algorithms
# Medium (29.89%)
# Total Accepted:    60.6K
# Total Submissions: 202.8K
# Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
#
# For an undirected graph with tree characteristics, we can choose any node as
# the root. The result graph is then a rooted tree. Among all possible rooted
# trees, those with minimum height are called minimum height trees (MHTs).
# Given such a graph, write a function to find all the MHTs and return a list
# of their root labels.
#
# Format
# The graph contains n nodes which are labeled from 0 to n - 1. You will be
# given the number n and a list of undirected edges (each edge is a pair of
# labels).
#
# You can assume that no duplicate edges will appear in edges. Since all edges
# are undirected, [0, 1] is the same as [1, 0] and thus will not appear
# together in edges.
#
# Example 1 :
#
#
# Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
#
# ⁠       0
# ⁠       |
# ⁠       1
# ⁠      / \
# ⁠     2   3
#
# Output: [1]
#
#
# Example 2 :
#
#
# Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
#
# ⁠    0  1  2
# ⁠     \ | /
# ⁠       3
# ⁠       |
# ⁠       4
# ⁠       |
# ⁠       5
#
# Output: [3, 4]
#
# Note:
#
#
# According to the definition of tree on Wikipedia: “a tree is an undirected
# graph in which any two vertices are connected by exactly one path. In other
# words, any connected graph without simple cycles is a tree.”
# The height of a rooted tree is the number of edges on the longest downward
# path between the root and a leaf.
#
#
#
# 连通图就是一颗树，n个结点的数有n-1条边
# 树中最长的没有分支的子树称为路径，通常它是最长的，根节点一定位于路径中
# 双指针法，一个从前向后，一个从后往前，它们的中点记为根节点
# 与当前节点相连接的节点个数称为度
# 叶子节点的度为1
# 最长路径的中间即为根节点，当最长路径的长度为奇数时，只有一个根节点，为偶数是是2个根节点，所以根节点一定是小于等于2个
# 相当于自下而上的 BFS，直到只剩下两个以下的节点
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        # n = 1时 根节点是其本身
        if n == 1:
            return [0]

        # 用于统计相互连接的节点（度）
        adj = [set() for _ in range(n)]
        for i, j in edges:
            adj[i].add(j)
            adj[j].add(i)

        # 叶子节点
        leaves = [i for i in range(n) if len(adj[i]) == 1]

        # 根节点最多为2个
        while n > 2:
            n = n - len(leaves) # 上一层节点的个数（内节点的个数）
            newLeaves = []
            for i in leaves:
                j = adj[i].pop()  # 取出一个和当前叶节点相连的内节点
                adj[j].remove(i)  # 删除内节点和该叶节点的连接
                if len(adj[j]) == 1:
                    # 如果内节点变为叶节点
                    newLeaves.append(j)
            leaves = newLeaves
        return leaves
