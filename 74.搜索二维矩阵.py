#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#
# https://leetcode-cn.com/problems/search-a-2d-matrix/description/
#
# algorithms
# Medium (35.78%)
# Likes:    80
# Dislikes: 0
# Total Accepted:    14.3K
# Total Submissions: 40K
# Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
#
# 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
#
#
# 每行中的整数从左到右按升序排列。
# 每行的第一个整数大于前一行的最后一个整数。
#
#
# 示例 1:
#
# 输入:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 3
# 输出: true
#
#
# 示例 2:
#
# 输入:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 13
# 输出: false
#
#
# 每行中的整数从左到右按升序排列。
# 每行的第一个整数大于前一行的最后一个整数。
# z 形有序数组
# 把其展开为一维数组即按行读取
# 给定序号，计算相应的坐标
# x = id // cols
# y = id % cols


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        # 等于是为了判断当 两个数相邻时，都能够被访问到
        while left <= right:
            mid = (left + right) // 2    # 中间位置
            tmp = matrix[mid // n][mid % n]
            if tmp < target:
                left = mid + 1
            elif tmp > target:
                right = mid - 1
            else:
                return True
        # 如果所有的元素均已访问
        return False
