#include "sort.h"

namespace sort
{
	using namespace std;

	// ������
	// start, end �ֱ��ʾ��ǰ��������Ŀ�ʼ�ͽ���λ��
	void Sorter::max_heapifty(vector<int>& nums, int start, int end)
	{
		// ���ڵ�Ϊ start, �ӽڵ���԰������������ڵ�son, son+1
		int parent = start, son = 2 * parent + 1;
		while (son <= end)
		{
			// ����������ӽڵ㣬�ҵ�����ӽڵ��λ��
			if (son + 1 <= end && nums[son + 1] > nums[son])
				son++; // ���ֵΪ�ҽڵ㣬�������������ڵ����
			if (nums[parent] > nums[son])
				return;
			else
			{
				swap(nums[parent], nums[son]); // �������ҽڵ�����ֵ�͸��ڵ�
				parent = son;
				son = 2 * parent + 1;
			}
		}
	}

	void Sorter::heap_sort(vector<int>& nums)
	{
		int n = nums.size();
		// �ȶ�ԭʼ����������� �ӵ�һ����Ҷ�ڵ� ���ҵ��� ���µ���
		// ��Ϊ��ǰ���ڵ��Ժ�Ķ�����������
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			max_heapifty(nums, i, n - 1);
		}

		// �ѶѶ�Ԫ�������λ�õ�Ԫ�ؽ��н������õ��µ��������� n ���������� 1-(n-1)
		// ������������Ϊ�µĴ����(ѭ������)
		for (int i = n - 1; i > 0; i--)
		{
			swap(nums[0], nums[i]);		  // �Ѿ���������� i ~ n - 1
			max_heapifty(nums, 0, i - 1); // ��������������� 0 ~ i - 1
		}
	}

	// ϣ������
	void Sorter::shell_sort(vector<int>& nums)
	{
		int n = nums.size(), i, j, inc, cur;
		// ���ó�ʼ����Ϊ ���鳤�ȵ�һ�㣬ÿ�ζ��۰룬ֱ��Ϊ1
		// ������ �� 4 �� �� 8 �� �� ÿ������֮����бȽ����ƶ�
		// ����Ӧ�ð������� ����ѭ��
		for (inc = n / 2; inc > 0; inc /= 2)
		{
			for (i = inc; i < n; i++)
			{
				cur = nums[i];
				for (j = i - inc; j >= 0 && nums[j] > cur; j -= inc)
				{
					nums[j + inc] = nums[j];
				}
				nums[j + inc] = cur;
			}
		}
	}

	// ѡ������
	void Sorter::select_sort(vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			int tmp = nums[i], ix = i;
			for (int j = i; j < n; j++)
			{
				if (nums[j] < tmp)
				{
					tmp = nums[j];
					ix = j; // ��Сֵ��λ��
				}
			}
			swap(nums[i], nums[ix]);
		}
	}

	// �������� ����Ԫ�ذ�
	void Sorter::quick_sort_swap(vector<int>& nums, int low, int high)
	{
		// �ݹ���� ֻʣһ��Ԫ��
		int lb = low, rb = high;
		if (lb >= rb)
			return;
		while (lb < rb)
		{
			// pivotѡ�� nums[lb] �������� ѡ��С�� pivot ����ֵ��pivot����
			for (; lb < rb && nums[rb] >= nums[lb]; rb--)
				;
			// ֻ�е� lb < rb ��ʱ�򣬲Ž�������Ϊ�����Ǿ��rb-1��ÿ�ζ�Ҫ�ж�lb < rb �Ƿ����
			if (lb < rb)
				swap(nums[lb++], nums[rb]);
			for (; lb < rb && nums[rb] >= nums[lb]; lb++)
				;
			// ��������ǰ�����жϽ����������Ƿ����
			if (lb < rb)
				swap(nums[rb--], nums[lb]);
		}
		quick_sort_swap(nums, low, lb - 1);
		quick_sort_swap(nums, lb + 1, high);
	}

	// ��������
	void Sorter::quick_sort(vector<int>& nums, int low, int high)
	{
		int lb = low, rb = high;
		if (lb >= rb)
			return;
		while (lb < rb)
		{
			int pivot = nums[lb];
			for (; lb < rb && nums[rb] >= pivot; rb--)
				;
			if (lb < rb)
				nums[lb++] = nums[rb];
			for (; lb < rb && nums[lb] <= pivot; lb++)
				;
			if (lb < rb)
				nums[rb--] = nums[lb];
			nums[lb] = pivot;
			quick_sort(nums, low, lb - 1);
			quick_sort(nums, lb + 1, high);
		}
	}

	// �鲢����
	void Sorter::merge_sorted(vector<int>& nums, int left, int mid, int right)
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
	void Sorter::merge_sorted_easy(vector<int>& nums, int left, int mid, int right)
	{
		// ע������Ҫ + 1
		vector<int> lArray(nums.begin() + left, nums.begin() + mid + 1);
		vector<int> rArray(nums.begin() + mid + 1, nums.begin() + right + 1);
		lArray.push_back(INT_MAX);
		rArray.push_back(INT_MAX);

		// �������鶼�Ǵ�0��ʼ����
		for (int i = left, lix = 0, rix = 0; i <= right; i++)
		{
			if (lArray[lix] < rArray[rix])
				nums[i] = lArray[lix++];
			else
				nums[i] = rArray[rix++];
		}
	}

	void Sorter::merge_sort(vector<int>& nums, int left, int right)
	{
		// ��ʣ��һ��ʱ�����أ����϶��µĵݹ�汾
		if (left >= right)
			return;
		int mid = left + (right - left) / 2;
		// ���ߺ��Ұ�߷ֱ�����
		merge_sort(nums, left, mid);
		merge_sort(nums, mid + 1, right);
		// �ϲ��������������
		// �������ҽ��бȽ�
		// merge_sorted(nums, left, mid, right);  // ��ͨ�汾
		merge_sorted_easy(nums, left, mid, right); // ����汾
	}

	// �鲢���� ���¶��ϵĵ����汾
	void Sorter::merge_sort_iteration(vector<int>& nums, int left, int right)
	{
		int n = nums.size();
		// �ȶ����ݰ����Ƚ��зֶ� ����Ϊ 1, 2, 4, 8...
		for (int seg = 1; seg < n; seg *= 2) {
			// ��ÿ�����ݽ�������
			for (int start = 0; start < n; start += seg * 2) {
				// ȷ���ָ������� �ָ�㲻�ܳ�������ĳ���
				int left = start, mid = min(start + seg - 1, n - 1), right = min(start + seg * 2 - 1, n - 1);
				//merge_sorted(nums, left, mid, right);  // ��ͨ�汾
				merge_sorted_easy(nums, left, mid, right); // ����汾
			}
		}
	}

	void Sorter::insert_sort(vector<int>& nums)
	{
		// ������������ֵ���β������������ǵĲ�������ֵ��������
		// ����������������б����������ֵ���ڵ�ǰ��ֵ����ô�Ͱ���ֵ����ƶ�һλ
		// �����ҵ�����λ�ã����µ�ǰ����ֵ������������һ�εĲ�������
		int n = nums.size(), i, j;
		for (i = 1; i < n; i++)
		{
			int cur = nums[i]; // ���뱣����ʱ��ֵ����Ϊ���ܻᱻ����
			for (j = i - 1; j >= 0 && nums[j] > cur; j--)
			{
				nums[j + 1] = nums[j];
			}
			nums[j + 1] = cur;
		}
	}
} // namespace sort

