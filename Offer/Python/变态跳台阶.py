class Solution:
    def jumpFloorII(self, number):
        if number < 2:
            return number
        ans = 1
        for _ in range(number - 1):
            ans = ans * 2
        return ans


# 数学归纳法
class Solution:
    def jumpFloorII(self, number):
        return 0 if number == 0 else 2**(number - 1)
