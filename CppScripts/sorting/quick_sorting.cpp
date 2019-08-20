// 快速排序
// https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F

#include "sorting.h"

void quick_sort(vector<int>& nums, int low, int high)
{
	// 递归出口 只剩一个元素
	int lb = low, rb = high;
	if (lb >= rb)
		return;
	while (lb < rb) {
		// pivot选择 nums[lb] 从右向左 选择小于 pivot 的数值和pivot交换
		for (; lb < rb && nums[rb] >= nums[lb]; rb--);
		// 只有当 lb < rb 的时候，才交换，因为上面那句对rb-1，每次都要判断lb < rb 是否成立
		if (lb < rb)
			swap(nums[lb++], nums[rb]);
		for (; lb < rb && nums[rb] >= nums[lb]; lb++);
		// 交换操作前必须判断交换的条件是否成立
		if(lb < rb)
			swap(nums[rb--], nums[lb]);
	}
	quick_sort(nums, low, lb - 1);
	quick_sort(nums, lb + 1, high);
}

void quick_sort1(vector<int>& nums, int low, int high)
{
	int lb = low, rb = high;
	if (lb >= rb) return;
	while (lb < rb) {
		int pivot = nums[lb];
		for (; lb < rb && nums[rb] >= pivot; rb--);
		if (lb < rb) nums[lb++] = nums[rb];
		for (; lb < rb && nums[lb] <= pivot; lb++);
		if (lb < rb) nums[rb--] = nums[lb];
		nums[lb] = pivot;
		quick_sort1(nums, low, lb - 1);
		quick_sort1(nums, lb + 1, high);
	}
}

int main()
{
	vector<int> nums = { 54, 38, 96, 23, 15, 72, 60, 45, 83, -1, -23 };
	print_vector(nums);
	quick_sort(nums, 0, nums.size() - 1);
	print_vector(nums);

	// 不交换 使用临时空间
	vector<int> nums1 = { 54, 38, 96, 23, 15, 72, 60, 45, 83, -1, -23 };
	print_vector(nums1);
	quick_sort1(nums1, 0, nums1.size() - 1);
	print_vector(nums1);
	return 0;
}
