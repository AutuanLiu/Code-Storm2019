class Solution:
    def movingCount(self, threshold, rows, cols):
        visited = [False] * (rows * cols)
        count = self.movingCountCore(threshold, rows, cols, 0, 0, visited)
        return count

    def movingCountCore(self, threshold, rows, cols, row, col, visited):
        count = 0
        if self.check(threshold, rows, cols, row, col, visited):
            visited[row * cols + col] = True
            count = 1 + self.movingCountCore(threshold, rows, cols, row-1, col, visited) + \
                        self.movingCountCore(threshold, rows, cols, row+1, col, visited) + \
                        self.movingCountCore(threshold, rows, cols, row, col-1, visited) + \
                        self.movingCountCore(threshold, rows, cols, row, col+1, visited)
        return count

    def check(self, threshold, rows, cols, row, col, visited):
        if row >= 0 and row < rows and col >= 0 and col < cols and self.digit_sum(row, col) <= threshold and not visited[row * cols + col]:
            return True
        return False

    def digit_sum(self, row, col):
        sums = 0
        while row != 0:
            sums += row % 10
            row //= 10
        while col != 0:
            sums += col % 10
            col //= 10
        return sums


if __name__ == '__main__':
    s = Solution()
    nums = s.movingCount(4, 4, 3) # 11
    nums1 = s.movingCount(3, 4, 3) # 9
    # nums2 = s.movingCount(2, 4, 3) # 6
    nums2 = s.movingCount(10, 1, 100) # 6
    print(nums, nums1, nums2)
