// leetcode_repos.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <iterator>
#include <iomanip>
#include <math.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

template<typename T> void print_vector(vector<T> nums)
{
	for (T& item : nums) {
		cout << item << ' ';
	}
	cout << endl;
}

void print_list(ListNode* head)
{
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}

template<typename T> void print_queue(T& q)
{
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << '\n';
}
