class Solution:
    def rectCover(self, number):
        if number < 3:
            return number
        f1 = 1
        f2 = 2
        for _ in range(3, number + 1):
            f3 = f1 + f2
            f1 = f2
            f2 = f3
        return f3
