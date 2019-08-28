# LeetCode2019

1. leetcode 代码练习
2. 剑指offer 练习题
3. 算法与数据结构
4. SQL

## 算法

### [排序算法](./CppScripts/sort)

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
```

### 数组输出

```cpp
template <typename T>
void print_vector(vector<T>& nums);

template <typename T>
void print_matrix(vector<vector<T>>& matrix);
```

### [libtorch](./CppScripts/torch-x) 使用案例

1. Mnist [libtorch](https://pytorch.org/cppdocs/) C++ 版本

### Deeplearning

1. dropout
2. batchnorm
3. layernorm
4. conv2d
5. pool2d
6. numpy 实现2层的全连接网络

## 语言

1. C++
2. Python
3. bash
4. SQL

## 信息

```bash
(torch36) λ cloc .
     382 text files.
     382 unique files.
      35 files ignored.

http://cloc.sourceforge.net v 1.64  T=0.84 s (440.9 files/s, 24341.1 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                            173            641           6167           5497
Python                         160            688           2981           3620
C/C++ Header                     4             30             11            186
Java                             5             11              1            156
SQL                             19             47            129            111
Bourne Shell                     3             17              9             63
CMake                            5             15             20             22
JSON                             1              0              0              5
-------------------------------------------------------------------------------
SUM:                           370           1449           9318           9660
-------------------------------------------------------------------------------
```

## Reference
1. [MisterBooo/LeetCodeAnimation: Demonstrate all the questions on LeetCode in the form of animation.（用动画的形式呈现解LeetCode题目的思路）](https://github.com/MisterBooo/LeetCodeAnimation)
2. [apachecn/awesome-algorithm: LeetCode, HackRank, 剑指offer, classic algorithm implementation](https://github.com/apachecn/awesome-algorithm)
3. [billryan/algorithm-exercise: Data Structure and Algorithm notes. 数据结构与算法/leetcode/lintcode题解/](https://github.com/billryan/algorithm-exercise)
4. [csujedihy/lc-all-solutions: My own leetcode solutions by python](https://github.com/csujedihy/lc-all-solutions)
5. [HuberTRoy/leetCode: :pencil2: 算法相关知识储备 LeetCode with Python](https://github.com/HuberTRoy/leetCode)
6. [xuelangZF/LeetCode: 正确的姿势，学习的态度来刷 LeetCode：高效的代码、简洁的注释、精炼的总结。](https://github.com/xuelangZF/LeetCode)
7. [zhedahht/CodingInterviewChinese2: 《剑指Offer》第二版源代码](https://github.com/zhedahht/CodingInterviewChinese2)
8. [C++ 语言参考 | Microsoft Docs](https://docs.microsoft.com/zh-cn/cpp/cpp/cpp-language-reference?view=vs-2017)


