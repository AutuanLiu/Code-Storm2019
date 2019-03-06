class Solution:
    def Fibonacci(self, n):
        if n < 2:
            return n
        f1 = 0
        f2 = 1
        for _ in range(2, n + 1):
            f3 = f1 + f2
            f1 = f2
            f2 = f3
        return f3
