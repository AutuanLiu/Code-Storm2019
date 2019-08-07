// 归并排序 迭代版本
// 两个有序数组的合并，也易于在链表上实现

#include "sorting.h"

void merge_sorted(vector<int>& nums, int left, int mid, int right)
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

// 自下而上的迭代版本
void merge_sort(vector<int>& nums, int left, int right)
{
	int n = nums.size();
	// 先对数据按长度进行分段 长度为 1, 2, 4, 8...
	for (int seg = 1; seg < n; seg << 1) {
		// 对每组数据进行排序
		for (int start = 0; start < n; start += seg << 1) {
			// 确定分割点的索引 分割点不能超过数组的长度
			int left = start, mid = min(start + seg, n - 1), right = min(start + seg * 2, n - 1);
			merge_sorted(nums, left, mid, right);
		}
	}
}

int main()
{
	vector<int> nums = { 123, 54, 38, 96, -23, 15, 72, -60, 45, 83, -1, -23 };
	print_vector(nums);
	merge_sort(nums, 0, nums.size() - 1);
	print_vector(nums);
	return 0;
}
