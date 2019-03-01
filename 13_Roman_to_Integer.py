# 13. Roman to Integer
# 从后往前
class Solution:
    def romanToInt(self, s: str) -> int:
        result = 0
        dic = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        for i in s[-1::-1]:
            symbol = 1
            if (i in ['I', 'X', 'C']) and result >= 5 * dic[i]:
                symbol = -1
            result += dic[i] * symbol
        return result

# 从前往后
class Solution(object):
    def romanToInt(self, s: str) -> int:
        lookup = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res = 0
        for i in range(len(s)):
            if i > 0 and lookup[s[i]] > lookup[s[i - 1]]:
                res += lookup[s[i]] - 2 * lookup[s[i - 1]]
            else:
                res += lookup[s[i]]
        return res