// 并査集的实现
// https://www.jianshu.com/p/fc17847b0a31

#include "leetcode_repos.h"

class UnionFindSet {
private:
    vector<int> parent;

public:
    // 构造函数
    UnionFindSet(int max_size)
        : parent(vector<int>(max_size))
    {
        // 初始化每一个元素的根节点都为自身
        for (int i = 0; i < max_size; ++i)
            parent[i] = i;
    }

    // 查找
    int find(int x)
    {
        return parent[x] == x ? x : find(parent[x]);
    }

    // 合并
    void to_union(int x1, int x2)
    {
        parent[find(x1)] = find(x2);
    }

    // 判断两个元素是否属于同一个集合
    bool is_same(int e1, int e2)
    {
        return find(e1) == find(e2);
    }
};

// 优化版本的并査集
// 按秩合并 路径压缩
// 秩表示为树的高度 一开始都是 0，最开始每个元素的父亲都是自己(索引表示)
class UnionFindSetopt {
private:
    vector<int> parent;
    vector<int> rank; // 秩

public:
    UnionFindSetopt(int max_size)
        : parent(vector<int>(max_size))
        , rank(vector<int>(max_size, 0))
    {
        for (int i = 0; i < max_size; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        // return x == parent[x] ? x : (parent[x] = find(parent[x]));
        if (x == parent[x])
            return x;
        else
            parent[x] = find(parent[x]);
    }

    void to_union(int x1, int x2)
    {
        int f1 = find(x1);
        int f2 = find(x2);
        if (rank[f1] > rank[f2])
            parent[f2] = f1;
        else {
            parent[f1] = f2;
            // 重要的是祖先的 rank，所以只用修改祖先的rank就可以了，子节点的rank不用管
            if (rank[f1] == rank[f2])
                ++rank[f2];
        }
    }

    bool is_same(int e1, int e2)
    {
        return find(e1) == find(e2);
    }
};

// 优化版本的并査集
// 按秩合并 路径压缩
// size表示为树中元素的个数 一开始都是 1，即每个元素各自代表一个集合，最开始每个元素的父亲都是自己(索引表示)
class UnionFindSetopt1 {
private:
    vector<int> parent;
    vector<int> size; // 子集合大小

public:
    UnionFindSetopt1(int max_size)
        : parent(vector<int>(max_size))
        , size(vector<int>(max_size, 1))
    {
        for (int i = 0; i < max_size; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        // return x == parent[x] ? x : (parent[x] = find(parent[x]));
        if (x == parent[x])
            return x;
        else
            parent[x] = find(parent[x]);
    }

    void to_union(int x1, int x2)
    {
        int f1 = find(x1);
        int f2 = find(x2);

        // 如果 f1==f2 则说明他们已经在一个集合里，不需要合并
        // 合并到更高的集合
        if (f1 != f2) {
            if (size[f1] > size[f2]) {
                parent[f2] = f1;
                size[f1] += size[f2];
            } else {
                parent[f1] = f2;
                size[f2] += size[f1];
            }
        }
    }

    bool is_same(int e1, int e2)
    {
        return find(e1) == find(e2);
    }
};

// leetcode 765