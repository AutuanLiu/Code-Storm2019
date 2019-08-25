#include "sort.h"
#include "print.h"

using namespace std;

int main()
{
	vector<int> nums = { 123, 54, 38, 96, -23, 15, 72, -60, 45, 83, -1, -23 };
	int n = nums.size();
	sort::print_vector(nums);
	sort::Sorter sorter;
	//sorter.merge_sort(nums, 0, n - 1); // �鲢����
	sorter.merge_sort_iteration(nums, 0, n - 1); // �鲢���������
	//sorter.quick_sort(nums, 0, n - 1); // ��������
	//sorter.quick_sort_swap(nums, 0, n - 1); // ��������
	//sorter.heap_sort(nums); // ������
	//sorter.shell_sort(nums); // ϣ������
	//sorter.select_sort(nums); // ѡ������
	//sorter.insert_sort(nums); // ��������
	sort::print_vector(nums);
	return 0;
}
