#
# @lc app=leetcode id=135 lang=python3
#
# [135] Candy
#
# https://leetcode.com/problems/candy/description/
#
# algorithms
# Hard (27.88%)
# Total Accepted:    98.9K
# Total Submissions: 353.8K
# Testcase Example:  '[1,0,2]'
#
# There are N children standing in a line. Each child is assigned a rating
# value.
#
# You are giving candies to these children subjected to the following
# requirements:
#
#
# Each child must have at least one candy.
# Children with a higher rating get more candies than their neighbors.
#
#
# What is the minimum candies you must give?
#
# Example 1:
#
#
# Input: [1,0,2]
# Output: 5
# Explanation: You can allocate to the first, second and third child with 2, 1,
# 2 candies respectively.
#
#
# Example 2:
#
#
# Input: [1,2,2]
# Output: 4
# Explanation: You can allocate to the first, second and third child with 1, 2,
# 1 candies respectively.
# ⁠            The third child gets 1 candy because it satisfies the above two
# conditions.
#
#
#
class Solution:
    def candy(self, ratings) -> int:
        n = len(ratings)
        if n < 1:
            return None
        if n == 1:
            return 1

        allocate = [1] * n

        # 先考虑左邻居
        for child in range(1, n):
            if ratings[child] > ratings[child - 1]:
                allocate[child] = allocate[child - 1] + 1

        # 再考虑右邻居
        for child in range(n - 2, -1, -1):
            if ratings[child] > ratings[child + 1]:
                allocate[child] = max(allocate[child], allocate[child + 1] + 1)

        return sum(allocate)


s = Solution()
x = [1, 0, 2]
y = [1, 3, 2, 2, 1]
res = s.candy(x)
print(res)
res = s.candy(y)
print(res)
