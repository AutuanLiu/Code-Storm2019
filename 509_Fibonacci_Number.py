# 509. Fibonacci Number
# 动态规划
# Runtime: 36 ms, faster than 44.34% of Python3 online submissions for Fibonacci Number.
# Memory Usage: 13 MB, less than 5.02% of Python3 online submissions for Fibonacci Number.
class Solution:
    def fib(self, N: int) -> int:
        if N == 0:
            return 0
        if N == 1:
            return 1
        a = 0
        b = 1
        for _ in range(2, N + 1):
            c = a + b
            a = b
            b = c
        return c
