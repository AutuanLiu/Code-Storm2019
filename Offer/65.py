class Solution:
    def __init__(self):
        self.visited = None  # 用于指示当前的元素是否已经被访问


    def hasPath(self, matrix, rows, cols, path):
        # 如果矩阵是空的，或者矩阵的行数和列数小于1或者访问路径为空，那么不存在要求的路径
        if matrix == None or rows < 1 or cols < 1 or path == None:
            return False

        self.visited = [False] * (rows * cols)
        pathLength = 0  # 表示已经访问过的路径长度
        for row in range(rows):
            for col in range(cols):
                if self.hasPathCore(matrix, rows, cols, row, col, path, pathLength):
                    return True
        return False

    def hasPathCore(self, matrix, rows, cols, row, col, path, pathLength):
        # 如果已经匹配的路径和要求的路径长度一致，则返回True
        if len(path) == pathLength:
            return True

        hasPath = False
        if row >= 0 and row < rows and col >= 0 and col < cols and matrix[row * cols + col] == path[pathLength] and not \
        self.visited[row * cols + col]:

            pathLength += 1
            self.visited[row * cols + col] = True

            # 访问上下左右四个方向
            hasPath = self.hasPathCore(matrix, rows, cols, row, col - 1, path, pathLength) or \
                      self.hasPathCore(matrix, rows, cols, row - 1, col, path, pathLength) or \
                      self.hasPathCore(matrix, rows, cols, row, col + 1, path, pathLength) or \
                      self.hasPathCore(matrix, rows, cols, row + 1, col, path, pathLength)

            # 如果上下左右都没有，则返回上一个节点继续搜索
            if not hasPath:
                pathLength -= 1
                self.visited[row * cols + col] = False

        return hasPath

# 解法2

class Solution1:
    def hasPath(self, matrix, rows, cols, path):
        for i in range(rows):
            for j in range(cols):
                # 先找到路径的第一个元素并作为起点
                if matrix[i * cols + j] == path[0]:
                    # 判断起点以后的路径在不在矩阵中
                    if self.find(list(matrix), rows, cols, path[1:], i, j):
                        return True
        return False

    def find(self, matrix, rows, cols, path, i, j):
        if not path:
            return True
        matrix[i * cols + j] = '0'
        # 向右访问
        if j + 1 < cols and matrix[i * cols + j + 1] == path[0]:
            return self.find(matrix, rows, cols, path[1:], i, j + 1)
        # 向左访问
        elif j - 1 >= 0 and matrix[i * cols + j - 1] == path[0]:
            return self.find(matrix, rows, cols, path[1:], i, j - 1)
        # 向下访问
        elif i + 1 < rows and matrix[(i + 1) * cols + j] == path[0]:
            return self.find(matrix, rows, cols, path[1:], i + 1, j)
        # 向上访问
        elif i - 1 >= 0 and matrix[(i - 1) * cols + j] == path[0]:
            return self.find(matrix, rows, cols, path[1:], i - 1, j)
        else:
            return False


s = Solution1()
m = ['a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h']
res = s.hasPath(m, 3, 4, 'bfce')
print(res)
