// 希尔排序 不稳定排序
// 分组插入排序，时间性能优于直接插入排序
// 当初始状态有序时，直接插入排序所需要的比较和移动次数均较小
// 由于分组的存在，相同的元素有可能会被分到不同的组别，从而导致有序数值的顺序可能发生变化，所以其实不稳定的排序方法
// 当增量为 1 时，希尔排序就退化为直接插入排序

#include "sorting.h"

void shell_sort(vector<int>& nums)
{
	int n = nums.size(), i, j, inc, cur;
	// 设置初始增量为 数组长度的一般，每次都折半，直到为1
	// 分两组 分 4 组 分 8 组 等 每组数据之间进行比较与移动
	// 所以应该包含的是 三层循环
	for (inc = n / 2; inc > 0; inc /= 2) {
		for (i = inc; i < n; i++) {
			cur = nums[i];
			for (j = i - inc; j >= 0 && nums[j] > cur; j -= inc) {
				nums[j + inc] = nums[j];
			}
			nums[j + inc] = cur;
		}
	}
}

int main()
{
	vector<int> nums;
	/*int tmp;
	while (cin >> tmp) {
		if (tmp == 0)
			break;
		nums.push_back(tmp);
	}*/

	nums = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	print_vector(nums);
	shell_sort(nums);
	print_vector(nums);
	return 0;
}