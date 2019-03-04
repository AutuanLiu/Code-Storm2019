# Floyd 算法 可以求出任意两点之间的最短路径

import numpy as np


def floydWarshall(graph):
    """Solves all pair shortest path via Floyd Warshall Algorithm"""
    for k in range(V):
        for i in range(V):
            for j in range(V):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    return graph


if __name__ == '__main__':
    # Number of vertices in the graph
    V = 4
    INF = np.inf
    # graph 使用邻接矩阵表示
    graph = [[0, 5, INF, 10], [INF, 0, 3, INF], [INF, INF, 0, 1], [INF, INF, INF, 0]]
    graph = floydWarshall(graph)
    print(graph)
