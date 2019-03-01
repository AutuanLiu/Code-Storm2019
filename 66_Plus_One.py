# Runtime: 40 ms, faster than 55.18% of Python3 online submissions for Plus One.
# Memory Usage: 13.2 MB, less than 5.29% of Python3 online submissions for Plus One.
# 先求出整数+1后变成列表
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = 0
        length = len(digits)
        for i in range(length):
            num += digits[i] * 10 ** (length - 1 - i)
        return list(map(int, str(num + 1)))
