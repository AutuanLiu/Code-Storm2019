// ���˼���ʵ��
// https://www.jianshu.com/p/fc17847b0a31

#include "leetcode_repos.h"

class UnionFindSet {
private:
	vector<int> parent;

public:
	// ���캯��
	UnionFindSet(int max_size)
		: parent(vector<int>(max_size))
	{
		// ��ʼ��ÿһ��Ԫ�صĸ��ڵ㶼Ϊ����
		for (int i = 0; i < max_size; ++i)
			parent[i] = i;
	}

	// ����
	int find(int x)
	{
		return parent[x] == x ? x : find(parent[x]);
	}

	// �ϲ�
	void to_union(int x1, int x2)
	{
		parent[find(x1)] = find(x2);
	}

	// �ж�����Ԫ���Ƿ�����ͬһ������
	bool is_same(int e1, int e2)
	{
		return find(e1) == find(e2);
	}
};

// �Ż��汾�Ĳ��˼�
// ���Ⱥϲ� ·��ѹ��
// �ȱ�ʾΪ���ĸ߶� һ��ʼ���� 0���ʼÿ��Ԫ�صĸ��׶����Լ�(������ʾ)
class UnionFindSetopt {
private:
	vector<int> parent;
	vector<int> rank; // ��

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
			// ��Ҫ�������ȵ� rank������ֻ���޸����ȵ�rank�Ϳ����ˣ��ӽڵ��rank���ù�
			if (rank[f1] == rank[f2])
				++rank[f2];
		}
	}

	bool is_same(int e1, int e2)
	{
		return find(e1) == find(e2);
	}
};


// �Ż��汾�Ĳ��˼�
// ���Ⱥϲ� ·��ѹ��
// size��ʾΪ����Ԫ�صĸ��� һ��ʼ���� 1����ÿ��Ԫ�ظ��Դ���һ�����ϣ��ʼÿ��Ԫ�صĸ��׶����Լ�(������ʾ)
class UnionFindSetopt1 {
private:
	vector<int> parent;
	vector<int> size; // �Ӽ��ϴ�С

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

		// ��� f1==f2 ��˵�������Ѿ���һ�����������Ҫ�ϲ�
		// �ϲ������ߵļ���
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