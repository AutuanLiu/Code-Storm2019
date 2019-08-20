// ��������
// https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F

#include "sorting.h"

void quick_sort(vector<int>& nums, int low, int high)
{
	// �ݹ���� ֻʣһ��Ԫ��
	int lb = low, rb = high;
	if (lb >= rb)
		return;
	while (lb < rb) {
		// pivotѡ�� nums[lb] �������� ѡ��С�� pivot ����ֵ��pivot����
		for (; lb < rb && nums[rb] >= nums[lb]; rb--);
		// ֻ�е� lb < rb ��ʱ�򣬲Ž�������Ϊ�����Ǿ��rb-1��ÿ�ζ�Ҫ�ж�lb < rb �Ƿ����
		if (lb < rb)
			swap(nums[lb++], nums[rb]);
		for (; lb < rb && nums[rb] >= nums[lb]; lb++);
		// ��������ǰ�����жϽ����������Ƿ����
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

	// ������ ʹ����ʱ�ռ�
	vector<int> nums1 = { 54, 38, 96, 23, 15, 72, 60, 45, 83, -1, -23 };
	print_vector(nums1);
	quick_sort1(nums1, 0, nums1.size() - 1);
	print_vector(nums1);
	return 0;
}
