class Solution:
    def NumberOf1(self, n):
        cnt = 0
        if n < 0:
            n = n & 0xffffffff
        while n:
            cnt += 1
            n = (n - 1) & n
        return cnt
