#include "leetcode_repos.h"

int hammingDistance(int x, int y)
{
	long long z = (x ^ y);
	int ret = 0;
	while (z != 0) {
		z = (z & (z - 1));
		ret++;
	}
	return ret;
}

int totalHammingDistance(vector<int>& nums)
{
	int ret = 0, n = nums.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ret += hammingDistance(nums[i], nums[j]);
		}
	}
	return ret;
}

int s2int(string x)
{
	int ret = 0;
	long long mask = 1;
	for (auto it = x.rbegin(); it != x.rend(); it++) {
		ret += (*it - '0') * mask;
		mask <<= 1;
	}
	return ret;
}

int main()
{
	vector<int> nums = { 4, 14, 4, 14 };
	int ret = totalHammingDistance(nums);
	cout << ret << endl;
	cout << stoi("1101", 0, 2) << endl;
	cout << s2int("1101") << endl;
	return 0;
}
