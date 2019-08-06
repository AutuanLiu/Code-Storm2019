// 归并排序
// 两个有序数组的合并，也易于在链表上实现

#include "sorting.h"

// 归并两个有序的数组
// 原地操作，所以首先要对左右两个排序数组进行复制
void merge_sorted(vector<int>& nums, int left, int mid, int right)
{
	// 注意这里要 + 1 
	vector<int> lArray(nums.begin() + left, nums.begin() + mid + 1);
	vector<int> rArray(nums.begin() + mid + 1, nums.begin() + right + 1);
	int lix = 0, rix = 0, ix = left;  // 两个数组都是从0开始访问
	int ln = lArray.size(), rn = rArray.size(), n = right - left + 1;

	// 合并上述的两个有序的数组
	// 当左右数组都还有元素没有遍历时
	while (lix < ln && rix < rn) {
		if (lArray[lix] < rArray[rix])
			nums[ix++] = lArray[lix++];
		else
			nums[ix++] = rArray[rix++];
	}

	// 存在剩余的情况
	while (lix < ln)
		nums[ix++] = lArray[lix++];
	while (rix < rn)
		nums[ix++] = rArray[rix++];
}

// 化简版本
void merge_sorted1(vector<int>& nums, int left, int mid, int right)
{
	// 注意这里要 + 1 
	vector<int> lArray(nums.begin() + left, nums.begin() + mid + 1);
	vector<int> rArray(nums.begin() + mid + 1, nums.begin() + right + 1);
	lArray.push_back(INT_MAX);
	rArray.push_back(INT_MAX);

	// 两个数组都是从0开始访问
	for (int i = left, lix = 0, rix = 0; i <= right; i++) {
		if (lArray[lix] < rArray[rix])
			nums[i] = lArray[lix++];
		else
			nums[i] = rArray[rix++];
	}
}

void merge_sort(vector<int>& nums, int left, int right)
{
	// 当剩余一个时，返回，自上而下的递归版本
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	// 左半边和右半边分别排序
	merge_sort(nums, left, mid);
	merge_sort(nums, mid + 1, right);
	// 合并两个有序的数组
	// 从左往右进行比较
	// merge_sorted(nums, left, mid, right);  // 普通版本
	merge_sorted1(nums, left, mid, right);    // 化简版本
}

int main()
{
	vector<int> nums = { 123, 54, 38, 96, -23, 15, 72, -60, 45, 83, -1, -23 };
	print_vector(nums);
	merge_sort(nums, 0, nums.size() - 1);
	print_vector(nums);
	return 0;
}
