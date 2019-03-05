# 使用 in 操作, 没有用到递增的条件
class Solution:
    # array 二维列表
    def Find(self, target, array):
        if len(array) > 0:
            n = len(array)
            for i in range(n):
                if target in array[i]:
                    return True
        return False


# 使用递增条件，选取右上角元素为初始条件
class Solution:
    # array 二维列表
    def Find(self, target, array):
        n_row, n_col = len(array), len(array[0])
        if n_row > 0:
            row_id, col_id = 0, n_col - 1
            while row_id < n_row and col_id >= 0:
                if array[row_id][col_id] == target:
                    return True
                elif array[row_id][col_id] > target:
                    col_id -= 1
                else:
                    row_id += 1
        return False
