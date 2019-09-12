## 排序算法

```cpp
void max_heapifty(vector<int>& nums, int start, int end); // 调整堆
void heap_sort(vector<int>& nums); // 堆排序
void shell_sort(vector<int>& nums); // 希尔排序
void select_sort(vector<int>& nums); // 选择排序
void quick_sort_swap(vector<int>& nums, int low, int high); // 快速排序-交换元素
void quick_sort(vector<int>& nums, int low, int high); // 快速排序
int get_partition(vector<int>& nums, int low, int high); // 快速排序获得分割点
int get_partition_swap(vector<int>& nums, int low, int high); // 快速排序获得分割点-交换元素
void quick_sort_iteration(vector<int>& nums, int low, int high); // 快速排序迭代版
void merge_sorted(vector<int>& nums, int left, int mid, int right); // 合并两个有序数组
void merge_sorted_easy(vector<int>& nums, int left, int mid, int right); // 化简版合并两个有序数组
void merge_sort(vector<int>& nums, int left, int right); // 归并排序
void merge_sort_iteration(vector<int>& nums, int left, int right); // 归并排序迭代版
void insert_sort(vector<int>& nums); // 插入排序
void bubble_sort_backward(std::vector<int>& nums); // 冒泡排序从后往前
void bubble_sort_forward(std::vector<int>& nums); // 冒泡排序从前往后
```

## 数组输出

```cpp
template <typename T>
void print_vector(vector<T>& nums);

template <typename T>
void print_matrix(vector<vector<T>>& matrix);
```
