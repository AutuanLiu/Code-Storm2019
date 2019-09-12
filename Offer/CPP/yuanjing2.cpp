#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int visit(vector<vector<int>>& nums, int row, int col, int m, int n)
{
    if ((row >= 0 && row < m) && (col >= 0 && col < n) && nums[row][col] == 1) {
        nums[row][col] = 0;
        return 1 + visit(nums, row - 1, col, m, n) + visit(nums, row + 1, col, m, n)
            + visit(nums, row, col - 1, m, n) + visit(nums, row, col + 1, m, n);
    }
    return 0;
}

int get_ret(vector<vector<int>>& nums, int m, int n)
{
    int ret = 0;
    // 任意一边相互接壤 则同属于同一个面板群
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[i][j] == 1) {
                // 计算光伏群的面板数
                // 判断相邻访问并置零
                int cur = visit(nums, i, j, m, n);
                ret = max(ret, cur);
            }
        }
    }
    return ret;
}

int main(void)
{
    // 数据读入
    int m, n;
    string s, s1;
    getline(cin, s);
    stringstream in(s);
    getline(in, s1, ',');
    m = stoi(s1);
    getline(in, s1, ',');
    n = stoi(s1);
    vector<vector<int>> nums(m);
    for (int i = 0; i < m; i++) {
        getline(cin, s);
        stringstream in(s);
        vector<int> nums1;
        while (getline(in, s1, ',')) {
            nums1.push_back(stoi(s1));
        }
        nums[i] = nums1;
    }
    cout << get_ret(nums, m, n) << endl;
    return 0;
}
