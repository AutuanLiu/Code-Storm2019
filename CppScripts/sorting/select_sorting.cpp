// 选择排序  不稳定的排序
#include "sorting.h"

void select_sort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		int tmp = nums[i], ix = i;
		for (int j = i; j < n; j++) {
			if (nums[j] < tmp) {
				tmp = nums[j];
				ix = j;  // 最小值的位置
			}
		}
		swap(nums[i], nums[ix]);
	}
}

int main()
{
	vector<int> nums = { 134, 54, 38, 96, 23, 15, 72, 60, 45, 83, -1, -23 };
	print_vector(nums);
	select_sort(nums);
	print_vector(nums);
	return 0;
}
