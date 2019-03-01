# 7. Reverse Integer
# Runtime: 56 ms, faster than 60.66% of Python3 online submissions for Reverse Integer.
# Memory Usage: 13.3 MB, less than 5.71% of Python3 online submissions for Reverse Integer.
class Solution:
    def reverse(self, x: int) -> int:
        ans = int(str(x)[-1::-1]) if x >= 0 else -int(str(-x)[-1::-1])
        if ans < -2**31 or ans > 2**31 - 1:
            return 0
        else:
            return ans

# 取模
# Runtime: 56 ms, faster than 60.66% of Python3 online submissions for Reverse Integer.
# Memory Usage: 13.3 MB, less than 5.71% of Python3 online submissions for Reverse Integer.
class Solution:
    def reverse(self, x: int) -> int:
        sign = 1
        if x < 0:
            sign = -1
            x = -x
        rev = 0
        while x != 0:
            pop = x % 10
            x //= 10
            rev = rev * 10 + pop
        rev *= sign
        if rev < -2**31 or rev > 2**31 - 1:
            return 0
        return rev
