#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#
# https://leetcode.com/problems/course-schedule/description/
#
# algorithms
# Medium (36.93%)
# Total Accepted:    194K
# Total Submissions: 525.4K
# Testcase Example:  '2\n[[1,0]]'
#
# There are a total of n courses you have to take, labeled from 0 to n-1.
#
# Some courses may have prerequisites, for example to take course 0 you have to
# first take course 1, which is expressed as a pair: [0,1]
#
# Given the total number of courses and a list of prerequisite pairs, is it
# possible for you to finish all courses?
#
# Example 1:
#
#
# Input: 2, [[1,0]]
# Output: true
# Explanation: There are a total of 2 courses to take.
# To take course 1 you should have finished course 0. So it is possible.
#
# Example 2:
#
#
# Input: 2, [[1,0],[0,1]]
# Output: false
# Explanation: There are a total of 2 courses to take.
# To take course 1 you should have finished course 0, and to take course 0 you
# should
# also have finished course 1. So it is impossible.
#
#
# Note:
#
#
# The input prerequisites is a graph represented by a list of edges, not
# adjacency matrices. Read more about how a graph is represented.
# You may assume that there are no duplicate edges in the input prerequisites.
#
#
#
class Solution:
    def create_graph(self, numCourses, prerequisites):
        graph = {k: [] for k in range(numCourses)}
        for item in prerequisites:
            graph[item[1]].append(item[0])
        return graph

    def topo_sort(self, graph):
        # 计数器
        cnt = {k: 0 for k in range(len(graph))}
        for item in graph.keys():
            for it in graph[item]:
                cnt[it] += 1
        # 创建队列
        queue = [k for k in cnt if cnt[k] == 0]
        seq = []

        while queue:
            item = queue.pop()
            seq.append(item)
            # 删除边
            for it in graph[item]:
                cnt[it] -= 1
                if cnt[it] == 0:
                    queue.append(it)
        return seq

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = self.create_graph(numCourses, prerequisites)  # 创建图
        seq = self.topo_sort(graph)  # 拓扑排序
        # 判断是否有环
        if len(seq) == numCourses:
            return True
        return False
