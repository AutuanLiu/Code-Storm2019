# 可以模拟魔方逆时针旋转的方法，一直做取出第一行的操作
# 输出并删除第一行后，再进行一次逆时针旋转
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        result = []
        while (len(matrix) > 0):
            result.append(matrix.pop(0))
            if not matrix or not matrix[0]:
                break
            matrix = self.turn(matrix)
        return result
    def turn(self,matrix):
        num_r = len(matrix)
        num_c = len(matrix[0])
        newmat = []
        for i in range(num_c):
            newmat2 = []
            for j in range(num_r):
                newmat2.append(matrix[j][i])
            newmat.append(newmat2)
        newmat.reverse()
        return newmat
