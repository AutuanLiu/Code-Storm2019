// �鲢���� �����汾
// ������������ĺϲ���Ҳ������������ʵ��

#include "sorting.h"

void merge_sorted(vector<int>& nums, int left, int mid, int right)
{
	// ע������Ҫ + 1 
	vector<int> lArray(nums.begin() + left, nums.begin() + mid + 1);
	vector<int> rArray(nums.begin() + mid + 1, nums.begin() + right + 1);
	lArray.push_back(INT_MAX);
	rArray.push_back(INT_MAX);

	// �������鶼�Ǵ�0��ʼ����
	for (int i = left, lix = 0, rix = 0; i <= right; i++) {
		if (lArray[lix] < rArray[rix])
			nums[i] = lArray[lix++];
		else
			nums[i] = rArray[rix++];
	}
}

// ���¶��ϵĵ����汾
void merge_sort(vector<int>& nums, int left, int right)
{
	int n = nums.size();
	// �ȶ����ݰ����Ƚ��зֶ� ����Ϊ 1, 2, 4, 8...
	for (int seg = 1; seg < n; seg << 1) {
		// ��ÿ�����ݽ�������
		for (int start = 0; start < n; start += seg << 1) {
			// ȷ���ָ������� �ָ�㲻�ܳ�������ĳ���
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
