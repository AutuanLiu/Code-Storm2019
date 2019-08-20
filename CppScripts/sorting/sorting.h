// sorting.h: 标准系统包含文件的包含文件或项目特定的包含文件。

#pragma once

#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

template <typename T>
void print_vector(vector<T>& nums)
{
    for (T& item : nums) {
        cout << item << ' ';
    }
    cout << endl;
}

template <typename T>
void print_matrix(vector<vector<T>>& matrix)
{
    for (vector<T>& item : matrix) {
        print_vector(item);
    }
}

void print_list(ListNode* head)
{
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

template <typename T>
void print_queue(T& q)
{
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << '\n';
}

void set_digits(int digit)
{
    cout << fixed << setprecision(digit);
}

template <typename T>
bool is_opposite_sign(T x, T y)
{
    return (x ^ y) < 0;
}
