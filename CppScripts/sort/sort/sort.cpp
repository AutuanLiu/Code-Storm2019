#include "sort.h"

namespace sort {
using namespace std;

// 堆排序
// start, end 分别表示当前无序数组的开始和结束位置
void Sorter::max_heapifty(vector<int>& nums, int start, int end)
{
    // 父节点为 start, 子节点可以包括左右两个节点son, son+1
    int parent = start, son = 2 * parent + 1;
    while (son <= end) {
        // 如果存在右子节点，找到最大子节点的位置
        if (son + 1 <= end && nums[son + 1] > nums[son])
            son++; // 最大值为右节点，其他情况都是左节点最大
        if (nums[parent] > nums[son])
            return;
        else {
            swap(nums[parent], nums[son]); // 交换左右节点的最大值和根节点
            parent = son;
            son = 2 * parent + 1;
        }
    }
}

void Sorter::heap_sort(vector<int>& nums)
{
    int n = nums.size();
    // 先对原始数据做大根堆 从第一个非叶节点 从右到左 从下到上
    // 认为当前根节点以后的都是无序数组
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapifty(nums, i, n - 1);
    }

    // 把堆顶元素与最后位置的元素进行交换，得到新的有序数组 n 和无序数组 1-(n-1)
    // 调整无序数组为新的大根堆(循环过程)
    for (int i = n - 1; i > 0; i--) {
        swap(nums[0], nums[i]); // 已经有序的数组 i ~ n - 1
        max_heapifty(nums, 0, i - 1); // 无序数组继续调整 0 ~ i - 1
    }
}

// 希尔排序
void Sorter::shell_sort(vector<int>& nums)
{
    int n = nums.size(), i, j, inc, cur;
    // 设置初始增量为 数组长度的一般，每次都折半，直到为1
    // 分两组 分 4 组 分 8 组 等 每组数据之间进行比较与移动
    // 所以应该包含的是 三层循环
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

// 选择排序
void Sorter::select_sort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int tmp = nums[i], ix = i;
        for (int j = i; j < n; j++) {
            if (nums[j] < tmp) {
                tmp = nums[j];
                ix = j; // 最小值的位置
            }
        }
        swap(nums[i], nums[ix]);
    }
}

// 快速排序 交换元素版
void Sorter::quick_sort_swap(vector<int>& nums, int low, int high)
{
    // 递归出口 只剩一个元素
    int lb = low, rb = high;
    if (lb >= rb)
        return;
    while (lb < rb) {
        // pivot选择 nums[lb] 从右向左 选择小于 pivot 的数值和pivot交换
        for (; lb < rb && nums[rb] >= nums[lb]; rb--)
            ;
        // 只有当 lb < rb 的时候，才交换，因为上面那句对rb-1，每次都要判断lb < rb 是否成立
        if (lb < rb)
            swap(nums[lb++], nums[rb]);
        for (; lb < rb && nums[rb] >= nums[lb]; lb++)
            ;
        // 交换操作前必须判断交换的条件是否成立
        if (lb < rb)
            swap(nums[rb--], nums[lb]);
    }
    quick_sort_swap(nums, low, lb - 1);
    quick_sort_swap(nums, lb + 1, high);
}

// 快速排序
void Sorter::quick_sort(vector<int>& nums, int low, int high)
{
    int lb = low, rb = high;
    if (lb >= rb)
        return;
    while (lb < rb) {
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

// 归并排序
void Sorter::merge_sorted(vector<int>& nums, int left, int mid, int right)
{
    // 注意这里要 + 1
    vector<int> lArray(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> rArray(nums.begin() + mid + 1, nums.begin() + right + 1);
    int lix = 0, rix = 0, ix = left; // 两个数组都是从0开始访问
    int ln = lArray.size(), rn = rArray.size(), n = right - left + 1;

    // 合并上述的两个有序的数组
    // 当左右数组都还有元素没有遍历时
    while (lix < ln && rix < rn) {
        if (lArray[lix] < rArray[rix])
            nums[ix++] = lArray[lix++];
        else
            nums[ix++] = rArray[rix++];
    }

    // 存在剩余的情况
    while (lix < ln)
        nums[ix++] = lArray[lix++];
    while (rix < rn)
        nums[ix++] = rArray[rix++];
}

// 化简版本
void Sorter::merge_sorted_easy(vector<int>& nums, int left, int mid, int right)
{
    // 注意这里要 + 1
    vector<int> lArray(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> rArray(nums.begin() + mid + 1, nums.begin() + right + 1);
    lArray.push_back(INT_MAX);
    rArray.push_back(INT_MAX);

    // 两个数组都是从0开始访问
    for (int i = left, lix = 0, rix = 0; i <= right; i++) {
        if (lArray[lix] < rArray[rix])
            nums[i] = lArray[lix++];
        else
            nums[i] = rArray[rix++];
    }
}

void Sorter::merge_sort(vector<int>& nums, int left, int right)
{
    // 当剩余一个时，返回，自上而下的递归版本
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    // 左半边和右半边分别排序
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    // 合并两个有序的数组
    // 从左往右进行比较
    // merge_sorted(nums, left, mid, right);  // 普通版本
    merge_sorted_easy(nums, left, mid, right); // 化简版本
}

// 归并排序 自下而上的迭代版本
void Sorter::merge_sort_iteration(vector<int>& nums, int left, int right)
{
    int n = nums.size();
    // 先对数据按长度进行分段 长度为 1, 2, 4, 8...
    for (int seg = 1; seg < n; seg *= 2) {
        // 对每组数据进行排序
        for (int start = 0; start < n; start += seg * 2) {
            // 确定分割点的索引 分割点不能超过数组的长度
            int left = start, mid = min(start + seg - 1, n - 1), right = min(start + seg * 2 - 1, n - 1);
            //merge_sorted(nums, left, mid, right);  // 普通版本
            merge_sorted_easy(nums, left, mid, right); // 化简版本
        }
    }
}

void Sorter::insert_sort(vector<int>& nums)
{
    // 将无序区的数值依次插入有序区，是的插入后的数值保持有序
    // 有序区从右向左进行遍历，如果数值大于当前数值，那么就把数值向后移动一位
    // 否则，找到插入位置，放下当前的数值，继续进行下一次的插入排序
    int n = nums.size(), i, j;
    for (i = 1; i < n; i++) {
        int cur = nums[i]; // 必须保存临时数值，因为可能会被覆盖
        for (j = i - 1; j >= 0 && nums[j] > cur; j--) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = cur;
    }
}
} // namespace sort
