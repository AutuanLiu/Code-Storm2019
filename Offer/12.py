# https://blog.csdn.net/MosBest/article/details/69264953
# 二进制法
# 快速幂算法
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if not -100.0 < x < 100.0:
            return
        return self.pow1(x, n) if n >= 0 else 1.0 / self.pow1(x, -n)

    def pow1(self, x, n):
        ans = 1.0
        while n != 0:
            if n % 2 == 1:
                ans *= x
            x *= x
            n //= 2
        return ans


# 二分幂法
# 时间复杂度 O(log_2^n)
# 空间复杂度 O(1)
class Solution:
    def myPow(self, x: float, n: int) -> float:
        return self.pow1(x, n) if n >= 0 else 1.0 / self.pow1(x, -n)

    def pow1(self, x, n):
        if n == 0:
            return 1
        if n == 1:
            return x
        ans = self.pow1(x, n // 2)
        ans *= ans
        if n % 2 == 1:
            ans *= x
        return ans


# 循环法 求x^n
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if not -100.0 < x < 100.0:
            return
        return self.pow1(x, n) if n >= 0 else 1.0 / self.pow1(x, -n)

    def pow1(self, x, n: int):
        ans = 1.0
        while n != 0:
            ans *= x
            n -= 1
        return ans
