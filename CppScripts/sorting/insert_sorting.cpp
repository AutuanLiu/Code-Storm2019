// 插入排序  稳定排序

#include "sorting.h"

void insert_sort(vector<int>& nums)
{
	// 将无序区的数值依次插入有序区，是的插入后的数值保持有序
	// 有序区从右向左进行遍历，如果数值大于当前数值，那么就把数值向后移动一位
	// 否则，找到插入位置，放下当前的数值，继续进行下一次的插入排序
	int n = nums.size(), i, j;
	for (i = 1; i < n; i++) {
		int cur = nums[i]; // 必须保存临时数值，因为可能会被覆盖
		for (j = i - 1; j >= 0 && nums[j] > cur; j--) {
			nums[j + 1] = nums[j];
		}
		nums[j + 1] = cur;
	}
}

int main()
{
	int v;
	vector<int> nums;

	// 输入 0 代表输入结束
	while (cin >> v) {
		if (v == 0)
			break;
		nums.push_back(v);
	}
	nums = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	print_vector(nums);  // 排序前
	insert_sort(nums);
	print_vector(nums);  // 排序后
	return 0;
}
