#include "print.h"
#include "sort.h"

using namespace std;

int main()
{
    vector<int> nums = { 123, 54, 38, 96, -23, 15, 72, -60, 45, 83, -1, -23 };
    int n = nums.size();
    sort::print_vector(nums);
    sort::Sorter sorter;
    //sorter.merge_sort(nums, 0, n - 1); // 归并排序
    sorter.merge_sort_iteration(nums, 0, n - 1); // 归并排序迭代版
    //sorter.quick_sort(nums, 0, n - 1); // 快速排序
    //sorter.quick_sort_swap(nums, 0, n - 1); // 快速排序
    //sorter.heap_sort(nums); // 堆排序
    //sorter.shell_sort(nums); // 希尔排序
    //sorter.select_sort(nums); // 选择排序
    //sorter.insert_sort(nums); // 插入排序
    sort::print_vector(nums);
    return 0;
}
