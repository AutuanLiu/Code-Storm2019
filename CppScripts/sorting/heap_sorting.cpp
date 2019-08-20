// ������ ��ȫ������
// С���� �����ӽڵ㶼�����丸�ڵ�
// ����� �����ӽڵ㶼С���丸�ڵ�
// https://zh.wikipedia.org/wiki/%E5%A0%86%E6%8E%92%E5%BA%8F
// ���ȶ�����
// �󶥶ѣ�arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
// С���ѣ�arr[i] <= arr[2i + 1] && arr[i] <= arr[2i + 2]
// �ȹ����ѣ�Ȼ��Ѹ��ŵ���󣬵õ������� An,
// ���ṹ��ѡ������ÿ��ȷ��һ����ֵ���ŵ���󣬲��ϵ����ѽṹ
// ����ͨ��һά����ʵ�ֵ�
// ������ڵ�Ϊ i ��ô��ڵ�Ϊ 2*i + 1, �ҽڵ�Ϊ 2 * i + 2, ��0��ʼ���
// �����һ����Ҷ�ӽ�㿪ʼ��Ҷ�����Ȼ���õ�������һ����Ҷ�ӽ�� arr.length/2-1��
// �������ϣ��������������

#include "sorting.h"

// start, end �ֱ��ʾ��ǰ��������Ŀ�ʼ�ͽ���λ��
void max_heapifty(vector<int>& nums, int start, int end)
{
	// ���ڵ�Ϊ start, �ӽڵ���԰������������ڵ�son, son+1
	int parent = start, son = 2 * parent + 1;
	while (son <= end) {
		// ����������ӽڵ㣬�ҵ�����ӽڵ��λ��
		if (son + 1 <= end && nums[son + 1] > nums[son])
			son++;  // ���ֵΪ�ҽڵ㣬�������������ڵ����
		if (nums[parent] > nums[son])
			return;
		else {
			swap(nums[parent], nums[son]);  // �������ҽڵ�����ֵ�͸��ڵ�
			parent = son;
			son = 2 * parent + 1;
		}
	}
}

void heap_sort(vector<int>& nums)
{
	int n = nums.size();
	// �ȶ�ԭʼ����������� �ӵ�һ����Ҷ�ڵ� ���ҵ��� ���µ���
	// ��Ϊ��ǰ���ڵ��Ժ�Ķ�����������
	for (int i = n / 2 - 1; i >= 0; i--) {
		max_heapifty(nums, i, n - 1);
	}

	// �ѶѶ�Ԫ�������λ�õ�Ԫ�ؽ��н������õ��µ��������� n ���������� 1-(n-1)
	// ������������Ϊ�µĴ����(ѭ������)
	for (int i = n - 1; i > 0; i--) {
		swap(nums[0], nums[i]);    // �Ѿ���������� i ~ n - 1
		max_heapifty(nums, 0, i - 1);  // ��������������� 0 ~ i - 1
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
