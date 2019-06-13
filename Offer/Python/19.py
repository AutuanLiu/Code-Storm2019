# 可以模拟魔方逆时针旋转的方法，一直做取出第一行的操作
# 输出并删除第一行后，再进行一次逆时针旋转
# 旋转思路
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        result = []
        while matrix:
            result.extend(matrix.pop(0))    # result 是一个列表
            if not matrix or not matrix[0]: # len([[]]) = 1
                break
            matrix = self.turn(matrix)    # 逆时针翻转矩阵
        return result

    def turn(self, matrix):
        num_r = len(matrix)
        num_c = len(matrix[0])
        newmat = []
        for i in range(num_c - 1, -1, -1):
            newmat2 = []
            for j in range(num_r):
                newmat2.append(matrix[j][i])
            newmat.append(newmat2)
        return newmat


class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        result = []
        if matrix:
            rows = len(matrix)
            columns = len(matrix[0])
            start = 0  # 每个循环开始的坐标
            while start * 2 < min(rows, columns):
                self.PrintMatrixInCircle(matrix, columns, rows, start, result)
                start += 1
        return result

    def PrintMatrixInCircle(self, matrix, columns, rows, start, result):
        endX = columns - 1 - start
        endY = rows - 1 - start

        # 从左到右打印一行
        for i in range(start, endX + 1):
            #number = matrix[start][i]
            result.append(matrix[start][i])

        # 从上到下打印一行
        if start < endY:
            for i in range(start + 1, endY + 1):
                #number = matrix[i][endX]
                result.append(matrix[i][endX])

        # 从右到左打印一行
        if start < endX and start < endY:
            for i in range(endX - 1, start - 1, -1):
                #number = matrix[endY][i]
                result.append(matrix[endY][i])

        # 从下到上打印一行
        if start < endX and start < endY - 1:
            for i in range(endY - 1, start, -1):
                #number = matrix[i][start]
                result.append(matrix[i][start])
