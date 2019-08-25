/*
排序算法的实现
*/

#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

namespace sort {
	class Sorter {
	public:
		Sorter() {}
		~Sorter() {}

		void max_heapifty(std::vector<int>& nums, int start, int end); // 调整堆
		void heap_sort(std::vector<int>& nums); // 堆排序
		void shell_sort(std::vector<int>& nums); // 希尔排序
		void select_sort(std::vector<int>& nums); // 选择排序
		void quick_sort_swap(std::vector<int>& nums, int low, int high); // 快速排序-交换元素
		void quick_sort(std::vector<int>& nums, int low, int high); // 快速排序
		void merge_sorted(std::vector<int>& nums, int left, int mid, int right); // 合并两个有序数组
		void merge_sorted_easy(std::vector<int>& nums, int left, int mid, int right); // 化简版合并两个有序数组
		void merge_sort(std::vector<int>& nums, int left, int right); // 归并排序
		void merge_sort_iteration(std::vector<int>& nums, int left, int right); // 归并排序迭代版
		void insert_sort(std::vector<int>& nums); // 插入排序
	};
} // namespace sort
