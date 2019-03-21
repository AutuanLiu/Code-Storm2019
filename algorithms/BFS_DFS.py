# DFS 深度优先搜索
# DFS 广度优先搜索


def dfs(graph, node, visited=[]):
    """DFS"""
    if node not in visited:
        visited.append(node)
        for n in graph[node]:
            dfs(graph, n, visited)
    return visited


def bfs(graph, start, path=[]):
    """BFS"""
    queue = [start]
    while queue:
        vertex = queue.pop(0)
        if vertex not in path:
            path.append(vertex)
            queue.extend(graph[vertex])
    return path


if __name__ == '__main__':

    graph1 = {
        'A': ['B', 'S'],
        'B': ['A'],
        'C': ['D', 'E', 'F', 'S'],
        'D': ['C'],
        'E': ['C', 'H'],
        'F': ['C', 'G'],
        'G': ['F', 'S'],
        'H': ['E', 'G'],
        'S': ['A', 'C', 'G']
    }

    graph2 = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F', 'G'], 'D': [], 'E': ['H'], 'F': [], 'G': [], 'H': [], 'S': []}
    visited = dfs(graph1, 'A', [])
    print(visited)

    visited = bfs(graph1, 'A', [])
    print(visited)

    visited = dfs(graph2, 'A', [])
    print(visited)

    visited = bfs(graph2, 'A', [])
    print(visited)
