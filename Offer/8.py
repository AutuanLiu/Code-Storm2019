class Solution:
    def jumpFloor(self, number):
        if number == 1:
            return 1
        if number == 2:
            return 2
        f1 = 1
        f2 = 2
        for _ in range(3, number + 1):
            f3 = f1 + f2
            f1 = f2
            f2 = f3
        return f3