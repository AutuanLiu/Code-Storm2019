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
