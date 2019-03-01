# https://www.jianshu.com/p/69669c7bd69e
# http://www.sohu.com/a/153858619_466939
# F(n) = F(n-1) + F(n-2) (n>=3)
# 递归
# 递归的时间复杂度是由阶梯数和最优子结构的个数决定的
# 时间复杂度 O(2^n)
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            return self.climbStairs(n - 1) + self.climbStairs(n - 2)


# 备忘录算法
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# Runtime: 36 ms, faster than 55.93% of Python3 online submissions for Climbing Stairs.
# Memory Usage: 13.3 MB, less than 5.18% of Python3 online submissions for Climbing Stairs
class Solution:
    def __init__(self):
        self.map = {}

    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n in self.map:
            return self.map[n]
        else:
            value = self.climbStairs(n - 1) + self.climbStairs(n - 2)
            self.map[n] = value
            return value


# 动态规划
# Runtime: 36 ms, faster than 55.93% of Python3 online submissions for Climbing Stairs.
# Memory Usage: 13.1 MB, less than 5.18% of Python3 online submissions for Climbing Stairs.
# 自底向上叠加
# 依次求 3, 4, 5
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        f1 = 1
        f2 = 2
        for _ in range(3, n + 1):
            ft = f1 + f2
            f1 = f2
            f2 = ft
        return ft


class Solution1:
    def jumpFloor(self, number):
        # write code here
        if number == 1:
            return 1
        if number == 2:
            return 2
        f1 = 1
        f2 = 2
        for _ in range(3, number + 1):
            f3 = f1 + f2
            f1, f2 = f2, f3
        return f3
