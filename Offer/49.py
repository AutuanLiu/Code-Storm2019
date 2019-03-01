class Solution:
    def StrToInt(self, s):
        ls = list(s.strip())
        if len(ls) == 0:
            return 0

        sign = -1 if ls[0] == '-' else 1
        if ls[0] in ['-', '+']:
            del ls[0]
        ret, i = 0, 0
        while i < len(ls):
            if ls[i].isdigit():
                ret = ret * 10 + ord(ls[i]) - ord('0')
                i += 1
            else:
                return 0
        return max(-2**31, min(sign * ret, 2**31 - 1))
