// ð������  �ȶ�����
// �Ӻ���ǰ����ÿ�ο���ȷ��һ����Сֵ�������ǰ��������ÿ�ο���ȷ��һ�����ֵ

#include "sorting.h"

void bubble_sort(vector<int>& nums)
{
	int n = nums.size();
	// �ܹ�Ҫ�Ƚ� n - 1 �� û�˱���ȷ��һ����Сֵ
	for (int i = 0; i < n - 1; i++) {
		bool hasChanged = false;
		// �Ӻ���ǰ����
		for (int j = n - 1; j > i; j--) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				hasChanged = true;
			}
		}

		// ������˱���û�з����κεĽ�������˵�������Ѿ�����
		// ֱ�ӽ���
		if (!hasChanged)
			return;
	}
}

void bubble_sort1(vector<int>& nums)
{
	int n = nums.size();
	// �ܹ�Ҫ�Ƚ� n - 1 �� ÿ�˱���ȷ��һ�����ֵ
	for (int i = n - 1; i > 0; i--) {
		bool hasChanged = false;
		// ��ǰ�������
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				hasChanged = true;
			}
		}

		// ������˱���û�з����κεĽ�������˵�������Ѿ�����
		// ֱ�ӽ���
		if (!hasChanged)
			return;
	}
}

int main()
{
	// �Ӻ���ǰ����
	vector<int> nums = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	print_vector(nums);
	bubble_sort(nums);
	print_vector(nums);

	// ��ǰ�������
	vector<int> nums1 = { 7, 3, 5, 8, 9, 1, 2, 4, 6 };
	print_vector(nums1);
	bubble_sort1(nums1);
	print_vector(nums1);
	return 0;
}
