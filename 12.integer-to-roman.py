#
# @lc app=leetcode id=12 lang=python3
#
# [12] Integer to Roman
#
class Solution:
    def intToRoman(self, num: int) -> str:
        romanNum = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"]
        numeral = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
        final, i = "", len(numeral) - 1

        if (num < 1) or (num > 3999):
            return 0

        while (num > 0):
            if (num - numeral[i] >= 0):
                final += romanNum[i]
                num -= numeral[i]
            else:
                i -= 1

        return final
