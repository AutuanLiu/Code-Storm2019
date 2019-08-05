// 冒泡排序  稳定排序
// 从后往前搜索每次可以确定一个最小值，如果从前往后搜索每次可以确定一个最大值

#include "sorting.h"

void bubble_sort(vector<int>& nums)
{
	int n = nums.size();
	// 总共要比较 n - 1 趟 没趟遍历确定一个最小值
	for (int i = 0; i < n - 1; i++) {
		bool hasChanged = false;
		// 从后往前遍历
		for (int j = n - 1; j > i; j--) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				hasChanged = true;
			}
		}

		// 如果本趟遍历没有发生任何的交换，则说明数组已经有序
		// 直接结束
		if (!hasChanged)
			return;
	}
}

void bubble_sort1(vector<int>& nums)
{
	int n = nums.size();
	// 总共要比较 n - 1 趟 每趟遍历确定一个最大值
	for (int i = n - 1; i > 0; i--) {
		bool hasChanged = false;
		// 从前往后遍历
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				hasChanged = true;
			}
		}

		// 如果本趟遍历没有发生任何的交换，则说明数组已经有序
		// 直接结束
		if (!hasChanged)
			return;
	}
}

int main()
{
	// 从后往前遍历
	vector<int> nums = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	print_vector(nums);
	bubble_sort(nums);
	print_vector(nums);

	// 从前往后遍历
	vector<int> nums1 = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	print_vector(nums1);
	bubble_sort1(nums1);
	print_vector(nums1);
	return 0;
}
