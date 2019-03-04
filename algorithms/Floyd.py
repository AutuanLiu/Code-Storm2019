# https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
# Python Program for Floyd Warshall Algorithm

# Number of vertices in the graph
V = 4

# Define infinity as the large enough value. This value will be
# used for vertices not connected to each other
INF = 99999

# Solves all pair shortest path via Floyd Warshall Algorithm
def floydWarshall(graph):

    dist = graph
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    print(dist)


graph = [[0,5,INF,10],
		[INF,0,3,INF],
		[INF, INF, 0, 1],
		[INF, INF, INF, 0]
		]

floydWarshall(graph);
