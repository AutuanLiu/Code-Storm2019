#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#
# https://leetcode.com/problems/course-schedule-ii/description/
#
# algorithms
# Medium (33.90%)
# Total Accepted:    134.4K
# Total Submissions: 396.4K
# Testcase Example:  '2\n[[1,0]]'
#
# There are a total of n courses you have to take, labeled from 0 to n-1.
#
# Some courses may have prerequisites, for example to take course 0 you have to
# first take course 1, which is expressed as a pair: [0,1]
#
# Given the total number of courses and a list of prerequisite pairs, return
# the ordering of courses you should take to finish all courses.
#
# There may be multiple correct orders, you just need to return one of them. If
# it is impossible to finish all courses, return an empty array.
#
# Example 1:
#
#
# Input: 2, [[1,0]]
# Output: [0,1]
# Explanation: There are a total of 2 courses to take. To take course 1 you
# should have finished
# course 0. So the correct course order is [0,1] .
#
# Example 2:
#
#
# Input: 4, [[1,0],[2,0],[3,1],[3,2]]
# Output: [0,1,2,3] or [0,2,1,3]
# Explanation: There are a total of 4 courses to take. To take course 3 you
# should have finished both
# ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
# finished course 0.
# So one correct course order is [0,1,2,3]. Another correct ordering is
# [0,2,1,3] .
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

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = self.create_graph(numCourses, prerequisites)    # 创建图
        seq = self.topo_sort(graph)    # 拓扑排序
        # 判断是否有环
        if len(seq) == numCourses:
            return seq
        return []
