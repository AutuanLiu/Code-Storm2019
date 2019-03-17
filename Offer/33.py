class Solution:
    def GetUglyNumber_Solution(self, index):
        if not index:
            return 0

        ugly_number = [1]*index  # 村相互空间开辟
        next_index, index2, index3, index5 = 1, 0, 0, 0

        while next_index < index:
            minValue = min(ugly_number[index2]*2, ugly_number[index3]*3,ugly_number[index5]*5)
            ugly_number[next_index] = minValue

            while ugly_number[index2]*2 <= ugly_number[next_index]:
                index2 += 1

            while ugly_number[index3]*3 <= ugly_number[next_index]:
                index3 += 1

            while ugly_number[index5]*5 <= ugly_number[next_index]:
                index5 += 1

            next_index += 1

        return ugly_number[-1]
