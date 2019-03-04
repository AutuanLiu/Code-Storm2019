#设置X R的初始值
def make_set(point):
    X[point] = point
    R[point] = 0


#节点的联通分量
def find(point):
    if X[point] != point:
        X[point] = find(X[point])
    return X[point]


#连接两个分量（节点）
def merge(point1, point2):
    r1 = find(point1)
    r2 = find(point2)
    if r1 != r2:
        if R[r1] > R[r2]:
            X[r2] = r1
        else:
            X[r1] = r2
            if R[r1] == R[r2]: R[r2] += 1


#KRUSKAL算法实现
def kruskal(graph):
    for vertice in graph['vertices']:
        make_set(vertice)

    minu_tree = set()

    edges = list(graph['edges'])
    edges.sort()    #按照边长从小到达排序
    for edge in edges:
        weight, vertice1, vertice2 = edge
        if find(vertice1) != find(vertice2):
            merge(vertice1, vertice2)
            minu_tree.add(edge)
    return minu_tree


if __name__ == "__main__":
    X = dict()
    R = dict()
    graph = {
        'vertices': ['A', 'B', 'C', 'D', 'E', 'F'],
        'edges': set([
            (1, 'A', 'B'),
            (5, 'A', 'C'),
            (3, 'A', 'D'),
            (4, 'B', 'C'),
            (2, 'B', 'D'),
            (1, 'C', 'D'),
        ])
    }

    result = kruskal(graph)
    print(result)
