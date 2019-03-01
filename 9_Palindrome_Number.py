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

# 翻转数字
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x >= 0:
            return x == self.rev_x(x)
        return False
    
    def rev_x(self, x):
        ans = 0
        while x != 0:
            p = x % 10
            ans = p + ans * 10
            x //= 10
        return ans
