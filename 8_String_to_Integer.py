# 8. String to Integer
# Runtime: 68 ms, faster than 45.05% of Python3 online submissions for String to Integer (atoi).
# Memory Usage: 13.3 MB, less than 5.00% of Python3 online submissions for String to Integer (atoi).
# 这题主要在边界条件的确定
class Solution:
    def __init__(self):
        self.hashtable = {str(k): k for k in range(10)}
        self.str_set = [str(i) for i in range(10)]
        self.str_set.append('.')

    def myAtoi(self, str: str) -> int:
        new_str = str.strip()
        # 只处理正常情况
        a = new_str != ""  # 非空字符串
        # 长度0
        if not a:
            return 0
        # 长度1
        if new_str[0] == '.':
            return 0
        if len(new_str) == 1 and new_str not in self.str_set:
            return 0
        if len(new_str) == 1 and new_str in self.str_set[:-1]:
            return int(new_str)
        # 长度 > 1
        if new_str[0] in self.str_set[:-1] and new_str[1] not in self.str_set:
            return int(new_str[0])
        if new_str[1] in self.str_set:
            # 求数值
            if new_str[0] == '-':
                sign = -1
                new_str = new_str[1:]
            elif new_str[0] == '+':
                sign = 1
                new_str = new_str[1:]
            else:
                sign = 1
            num = sign * self.get_num(new_str)
            # 边界问题
            if num < 0 and num < -2**31:
                return -2**31
            if num > 0 and num > 2**31 - 1:
                return 2**31 - 1
            return num
        else:
            return 0

    def get_num(self, new_str):
        num = 0
        for char in new_str:
            if char not in self.hashtable:
                break
            num = num * 10 + self.hashtable[char]
        return num


# https://leetcode.com/problems/string-to-integer-atoi/discuss/4673/60ms-python-solution-OJ-says-this-beats-100-python-submissions
# Runtime: 68 ms, faster than 45.05% of Python3 online submissions for String to Integer (atoi).
# Memory Usage: 13.5 MB, less than 5.00% of Python3 online submissions for String to Integer (atoi).
class Solution(object):
    def myAtoi(self, s):
        if len(s) == 0:return 0
        ls = list(s.strip())

        sign = -1 if ls[0] == '-' else 1
        if ls[0] in ['-', '+']:
            del ls[0]
        ret, i = 0, 0
        while i < len(ls) and ls[i].isdigit():
            ret = ret * 10 + ord(ls[i]) - ord('0')
            i += 1
        return max(-2**31, min(sign * ret, 2**31 - 1))


s = Solution()
print(s.myAtoi(" -"))
print(s.myAtoi(""))
print(s.myAtoi(" -42"))
print(s.myAtoi(" 42"))
print(s.myAtoi(" 42"))
print(s.myAtoi(" 4.2abc"))
print(s.myAtoi(" -abc"))
print(s.myAtoi(" +"))
print(s.myAtoi("-+23"))
print(s.myAtoi("abc"))
print(s.myAtoi("."))
print(s.myAtoi(".12"))
print(s.myAtoi("1a"))
