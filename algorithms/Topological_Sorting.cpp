// https: //www.jianshu.com/p/b59db381561a
/*
在图论中，拓扑排序（Topological Sorting）是一个有向无环图（DAG, Directed Acyclic Graph）的所有顶点的线性序列。
且该序列必须满足下面两个条件：
1. 每个顶点出现且只出现一次。 若存在一条从顶点 A 到顶点 B 的路径，那么在序列中顶点 A 出现在顶点 B 的前面。
2. 有向无环图（DAG）才有拓扑排序，非DAG图没有拓扑排序一说
*/

/* 求拓扑排序
1. 从 DAG 图中选择一个 没有前驱（即入度为0）的顶点并输出
2. 从图中删除该顶点和所有以它为起点的有向边
3. 重复 1 和 2 直到当前的 DAG 图为空
4. 如果DAG图不为空且当前图中不存在无前驱的顶点为止。说明有向图中必然存在环。
5. 一个有向无环图可以有一个或多个拓扑排序序列
6. 拓扑排序通常用来排序具有依赖关系的任务
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

/************************类声明************************/
class Graph
{
    int V;          // 顶点个数
    list<int> *adj; // 邻接表
    queue<int> q;   // 维护一个入度为0的顶点的集合
    int *indegree;  // 记录每个顶点的入度
  public:
    Graph(int V);               // 构造函数
    ~Graph();                   // 析构函数
    void addEdge(int v, int w); // 添加边
    bool topological_sort();    // 拓扑排序
};

/************************类定义************************/
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    indegree = new int[V]; // 入度全部初始化为0
    for (int i = 0; i < V; ++i)
        indegree[i] = 0;
}

Graph::~Graph()
{
    delete[] adj;
    delete[] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    ++indegree[w];
}

bool Graph::topological_sort()
{
    for (int i = 0; i < V; ++i)
        if (indegree[i] == 0)
            q.push(i); // 将所有入度为0的顶点入队

    int count = 0; // 计数，记录当前已经输出的顶点数
    while (!q.empty())
    {
        int v = q.front(); // 从队列中取出一个顶点
        q.pop();

        cout << v << " "; // 输出该顶点
        ++count;
        // 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
        list<int>::iterator beg = adj[v].begin();
        for (; beg != adj[v].end(); ++beg)
            if (!(--indegree[*beg]))
                q.push(*beg); // 若入度为0，则入栈
    }

    if (count < V)
        return false; // 没有输出全部顶点，有向图中有回路
    else
        return true; // 拓扑排序成功
}

int main()
{
    Graph g(6); // 创建图
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topological_sort();
    return 0;
}
