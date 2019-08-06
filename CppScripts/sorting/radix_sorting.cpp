// 基数排序

#include "sorting.h"

// 获取某数字的第k位数字 十进制

int ndigits(int num)
{
	int digits = 0;
	for (; num != 0; num /= 10, digits++);
	return digits;
}

// 暂时不考虑负数
int kth_digit(int num, int k)
{
	num /= pow(10, k);
	return num % 10;
}

void radix_sort(vector<int>& nums)
{
	vector<vector<int>> bullet(10);
	int max_v = *max_element(nums.begin(), nums.end());
	int n = ndigits(max_v), m = nums.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int id = kth_digit(nums[j], i);
			bullet[id].push_back(nums[j]);
		}

		// 获取最新的数据
		int idx = 0;
		for (int i = 0; i < 10; i++) {
			if (bullet[i].empty()) continue;
			for (int k = 0; k < bullet[i].size(); k++) {
				nums[idx++] = bullet[i][k];
			}
		}

		// 清空桶 保证下次是可以正常使用的
		for (int i = 0; i < 10; i++) {
			bullet[i].clear();
		}
	}
}

int main()
{
	vector<int> nums = { 123, 54, 38, 96, 23, 15, 72, 60, 45, 83, 1, 23 };
	print_vector(nums);
	radix_sort(nums);
	print_vector(nums);
	return 0;
}
