// ϣ������ ���ȶ�����
// �����������ʱ����������ֱ�Ӳ�������
// ����ʼ״̬����ʱ��ֱ�Ӳ�����������Ҫ�ıȽϺ��ƶ���������С
// ���ڷ���Ĵ��ڣ���ͬ��Ԫ���п��ܻᱻ�ֵ���ͬ����𣬴Ӷ�����������ֵ��˳����ܷ����仯��������ʵ���ȶ������򷽷�
// ������Ϊ 1 ʱ��ϣ��������˻�Ϊֱ�Ӳ�������

#include "sorting.h"

void shell_sort(vector<int>& nums)
{
	int n = nums.size(), i, j, inc, cur;
	// ���ó�ʼ����Ϊ ���鳤�ȵ�һ�㣬ÿ�ζ��۰룬ֱ��Ϊ1
	// ������ �� 4 �� �� 8 �� �� ÿ������֮����бȽ����ƶ�
	// ����Ӧ�ð������� ����ѭ��
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