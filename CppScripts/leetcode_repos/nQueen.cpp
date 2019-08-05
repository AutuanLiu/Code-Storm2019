#include "leetcode_repos.h"

bool isLegal(int row, int col, vector<string>& v, int n)
{
	for (int i = 0; i < row; ++i)
		if (v[i][col] == 'Q')
			return false;
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
		if (v[i][j] == 'Q')
			return false;
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
		if (v[i][j] == 'Q')
			return false;
	return true;
}

void snqHelp(vector<vector<string>>& res, vector<string>& v, int row, int n)
{
	if (row == n) {
		res.push_back(v);
		return;
	}

	for (int col = 0; col < n; ++col) {
		if (isLegal(row, col, v, n)) {
			v[row][col] = 'Q';
			snqHelp(res, v, row + 1, n);
			v[row][col] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n)
{
	vector<vector<string>> res;
	vector<string> v(n, string(n, '.'));
	snqHelp(res, v, 0, n);
	return res;
}

int main(int argc, char const* argv[])
{
	int n;
	cout << "input n :";
	cin >> n;
	vector<vector<string>> res = solveNQueens(n);
	for (auto vstr : res) {
		for (auto x : vstr)
			cout << x << endl;
		cout << endl
			<< endl;
	}
	cout << "Total solution :" << res.size() << endl;
	return 0;
}
