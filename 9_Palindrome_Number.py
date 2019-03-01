# str
# Runtime: 244 ms, faster than 82.30% of Python3 online submissions for Palindrome Number.
# Memory Usage: 13.4 MB, less than 5.03% of Python3 online submissions for Palindrome Number.
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x >= 0:
            str_x = str(x)
            if str_x == str_x[-1::-1]:
                return True
        return False


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        else:
            str_x = str(x)
            if str_x == str_x[-1::-1]:
                return True
            else:
                return False


# 翻转数字
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        return x == self.rev_x(x)

    def rev_x(self, x):
        ans = 0
        while x != 0:
            p = x % 10
            ans = p + ans * 10
            x //= 10
        return ans


# 翻转一半数字
# 时间复杂度 O(log10 n)
# 空间复杂度 O(1)
# Runtime: 252 ms, faster than 75.17% of Python3 online submissions for Palindrome Number.
# Memory Usage: 13.6 MB, less than 5.03% of Python3 online submissions for Palindrome Number.
# Now the question is, how do we know that we've reached the half of the number?
# Since we divided the number by 10, and multiplied the reversed number by 10,
# when the original number is less than the reversed number,
# it means we've processed half of the number digits.
# When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
# For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
# since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
# 千位 > 百位 > 十位 > 个位
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        rev_x = 0
        while x > rev_x:
            rev_x = rev_x * 10 + x % 10
            x //= 10
        return x == rev_x or x == rev_x // 10
