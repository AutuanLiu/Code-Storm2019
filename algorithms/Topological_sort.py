# https://www.jianshu.com/p/ffd47d2527c7
# 由于这是有向图，所以邻接字典做了特殊的约定，每一个节点所能访问到的节点（直接或间接）均显示在该节点的集合中


#朴素拓扑排序
#G为邻接字典
def naiveTopoSort(G, S=None):
    if S is None:
        S = set(G.keys())
    if len(S) == 1:
        return list(S)
    s = S.pop()    # 集合是无序的
    seq = naiveTopoSort(G, S)
    minIdx = 0
    for i, v in enumerate(seq):
        if s in G[v]:
            minIdx = i + 1
    seq.insert(minIdx, s)
    return seq


#有向无环图的邻接字典
G = {'a': {'b', 'c', 'd', 'e', 'f'}, 'b': {'c', 'd', 'e', 'f'}, 'c': {'d', 'e', 'f'}, 'd': {'e', 'f'}, 'e': {'f'}, 'f': {}}

res = naiveTopoSort(G)
print(res)


# 使用循环进行拓扑排序
def topoSort(G):
    # 初始化计算被指向节点的字典(入度)
    cnt = {u: 0 for u in G.keys()}
    # 若某节点被其他节点指向，该节点计算量+1
    for u in G.keys():
        for v in G[u]:
            cnt[v] += 1
    # 收集被指向数为0的节点,此时Q只有一个节点，即起始节点a(选择入度为0的点)
    # 以队列作为数据结构，末端为队首
    Q = [u for u in cnt.keys() if cnt[u] == 0]    # 初始队列
    # 记录结果
    seq = []
    while Q:
        s = Q.pop()
        seq.append(s)    # 加入拓扑序列
        # 删除连接
        for u in G[s]:
            cnt[u] -= 1    # 入度-1
            if cnt[u] == 0:
                Q.append(u)
    # if len(seq) < len(G.keys()):
    #     print('有环存在')
    return seq


# 有向无环图的邻接字典，只包含直接连接
G = {'a': {'b', 'f'}, 'b': {'c', 'd', 'f'}, 'c': {'d'}, 'd': {'e', 'f'}, 'e': {'f'}, 'f': {}}

res = topoSort(G)
print(res)


# 在DAG中DFS中顶点的出栈顺序即逆拓扑序
def topological_sort(graph):

    is_visit = {node: False for node in graph}
    li = []

    def dfs(graph, start_node):
        for end_node in graph[start_node]:
            if not is_visit[end_node]:
                is_visit[end_node] = True
                dfs(graph, end_node)
        li.append(start_node)

    for start_node in graph:
        if not is_visit[start_node]:
            is_visit[start_node] = True
            dfs(graph, start_node)

    li.reverse()
    return li


G = {'a': {'b', 'f'}, 'b': {'c', 'd', 'f'}, 'c': {'d'}, 'd': {'e', 'f'}, 'e': {'f'}, 'f': {}}
li = topological_sort(G)
print(li)
