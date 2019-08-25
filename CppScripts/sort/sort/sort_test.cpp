#include "sort.h"
#include "print.h"

using namespace std;

int main()
{
	vector<int> nums = { 123, 54, 38, 96, -23, 15, 72, -60, 45, 83, -1, -23 };
	int n = nums.size();
	sort::print_vector(nums);
	sort::Sorter sorter;
	//sorter.merge_sort(nums, 0, n - 1); // ¹é²¢ÅÅĞò
	sorter.merge_sort_iteration(nums, 0, n - 1); // ¹é²¢ÅÅĞòµü´ú°æ
	//sorter.quick_sort(nums, 0, n - 1); // ¿ìËÙÅÅĞò
	//sorter.quick_sort_swap(nums, 0, n - 1); // ¿ìËÙÅÅĞò
	//sorter.heap_sort(nums); // ¶ÑÅÅĞò
	//sorter.shell_sort(nums); // Ï£¶ûÅÅĞò
	//sorter.select_sort(nums); // Ñ¡ÔñÅÅĞò
	//sorter.insert_sort(nums); // ²åÈëÅÅĞò
	sort::print_vector(nums);
	return 0;
}
