// 堆排序 完全二叉树
// 小根堆 所有子节点都大于其父节点
// 大根堆 所有子节点都小于其父节点
// https://zh.wikipedia.org/wiki/%E5%A0%86%E6%8E%92%E5%BA%8F
// 不稳定排序
// 大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
// 小顶堆：arr[i] <= arr[2i + 1] && arr[i] <= arr[2i + 2]
// 先构建堆，然后把根放到最后，得到有序区 An,
// 树结构的选择排序，每次确定一个最值，放到最后，不断调整堆结构
// 堆是通过一维数组实现的
// 假设根节点为 i 那么左节点为 2*i + 1, 右节点为 2 * i + 2, 从0开始编号
// 从最后一个非叶子结点开始（叶结点自然不用调整，第一个非叶子结点 arr.length/2-1）
// 从下至上，从右至左调整。

#include "sorting.h"

// start, end 分别表示当前无序数组的开始和结束位置
void max_heapifty(vector<int>& nums, int start, int end)
{
	// 父节点为 start, 子节点可以包括左右两个节点son, son+1
	int parent = start, son = 2 * parent + 1;
	while (son <= end) {
		// 如果存在右子节点，找到最大子节点的位置
		if (son + 1 <= end && nums[son + 1] > nums[son])
			son++;  // 最大值为右节点，其他情况都是左节点最大
		if (nums[parent] > nums[son])
			return;
		else {
			swap(nums[parent], nums[son]);  // 交换左右节点的最大值和根节点
			parent = son;
			son = 2 * parent + 1;
		}
	}
}

void heap_sort(vector<int>& nums)
{
	int n = nums.size();
	// 先对原始数据做大根堆 从第一个非叶节点 从右到左 从下到上
	// 认为当前根节点以后的都是无序数组
	for (int i = n / 2 - 1; i >= 0; i--) {
		max_heapifty(nums, i, n - 1);
	}

	// 把堆顶元素与最后位置的元素进行交换，得到新的有序数组 n 和无序数组 1-(n-1)
	// 调整无序数组为新的大根堆(循环过程)
	for (int i = n - 1; i > 0; i--) {
		swap(nums[0], nums[i]);    // 已经有序的数组 i ~ n - 1
		max_heapifty(nums, 0, i - 1);  // 无序数组继续调整 0 ~ i - 1
	}
}

int main()
{
	vector<int> nums = { 54, 38, 96, 23, 15, 123, 72, 60, 45, 83, -1, -23 };
	print_vector(nums);
	heap_sort(nums);
	print_vector(nums);
	return 0;
}
