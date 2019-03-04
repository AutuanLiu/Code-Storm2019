import heapq


def dijkstra(graph, source):
    priority_queue = []
    # The cost is 0, because the distance between source to itself is 0
    heapq.heappush(priority_queue, (0, source))
    visited = {}
    # basically the same as a normal BFS
    while priority_queue:
        # dequeue from the priority queue
        # dequeue the minimum cost path
        (current_distance, current) = heapq.heappop(priority_queue)

        # When we extract min from the priority queue
        # we know that we have found the minimum cost path to this node
        # so we consider it visited
        visited[current] = current_distance

        if current not in graph: continue
        for neighbour, distance in graph[current].items():
            # We only continue to explore neighbours that have been visited
            # (same as a normal BFS)
            if neighbour in visited: continue
            # If we haven't found the min cost path to this node, we push the new distance back onto the queue
            # because this is a min queue, if the new distance is the new min cost path, it will be at the front of the queue
            new_distance = current_distance + distance
            heapq.heappush(priority_queue, (new_distance, neighbour))

    return visited


if __name__ == '__main__':
    graph = {
        'A': {
            'B': 20,
            'D': 80,
            'G': 90
        },
        'B': {
            'F': 10
        },
        'F': {
            'C': 10,
            'D': 40
        },
        'C': {
            'F': 50,
            'D': 10,
            'H': 20
        },
        'D': {
            'G': 20,
            'C': 10
        },
        'H': {},
        'G': {
            'A': 20
        },
        'E': {
            'B': 50,
            'G': 30
        }
    }

    path = dijkstra(graph, 'A')
    print(path)
