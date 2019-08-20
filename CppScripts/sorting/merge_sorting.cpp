// �鲢����
// ������������ĺϲ���Ҳ������������ʵ��

#include "sorting.h"

// �鲢�������������
// ԭ�ز�������������Ҫ��������������������и���
void merge_sorted(vector<int>& nums, int left, int mid, int right)
{
	// ע������Ҫ + 1 
	vector<int> lArray(nums.begin() + left, nums.begin() + mid + 1);
	vector<int> rArray(nums.begin() + mid + 1, nums.begin() + right + 1);
	int lix = 0, rix = 0, ix = left;  // �������鶼�Ǵ�0��ʼ����
	int ln = lArray.size(), rn = rArray.size(), n = right - left + 1;

	// �ϲ��������������������
	// ���������鶼����Ԫ��û�б���ʱ
	while (lix < ln && rix < rn) {
		if (lArray[lix] < rArray[rix])
			nums[ix++] = lArray[lix++];
		else
			nums[ix++] = rArray[rix++];
	}

	// ����ʣ������
	while (lix < ln)
		nums[ix++] = lArray[lix++];
	while (rix < rn)
		nums[ix++] = rArray[rix++];
}

// ����汾
void merge_sorted1(vector<int>& nums, int left, int mid, int right)
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

void merge_sort(vector<int>& nums, int left, int right)
{
	// ��ʣ��һ��ʱ�����أ����϶��µĵݹ�汾
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	// ���ߺ��Ұ�߷ֱ�����
	merge_sort(nums, left, mid);
	merge_sort(nums, mid + 1, right);
	// �ϲ��������������
	// �������ҽ��бȽ�
	// merge_sorted(nums, left, mid, right);  // ��ͨ�汾
	merge_sorted1(nums, left, mid, right);    // ����汾
}

int main()
{
	vector<int> nums = { 123, 54, 38, 96, -23, 15, 72, -60, 45, 83, -1, -23 };
	print_vector(nums);
	merge_sort(nums, 0, nums.size() - 1);
	print_vector(nums);
	return 0;
}
