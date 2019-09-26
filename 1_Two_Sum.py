# https://leetcode-cn.com/problems/two-sum/
# 关键条件：
# 每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
#
# 暴力解决
# 时间复杂度 O(n^2)
# 空间复杂度 O(n)
# 执行用时: 3996 ms, 在Two Sum的Python3提交中击败了33.74% 的用户
# 内存消耗: 13.8 MB, 在Two Sum的Python3提交中击败了0.84% 的用户
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for idx, value in enumerate(nums):
            diff = target - value
            # 同一个数值不可以使用多次, 从下一个索引开始遍历
            for idx1 in range(idx + 1, length):
                if nums[idx1] == diff:
                    return [idx, idx1]
        return None


# 两遍 hash 表
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# 执行用时: 96 ms, 在Two Sum的Python3提交中击败了56.18% 的用户
# 内存消耗: 14.8 MB, 在Two Sum的Python3提交中击败了0.84% 的用户
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for idx, value in enumerate(nums):
            hashmap[value] = idx

        for idx, value in enumerate(nums):
            diff = target - value
            # 同一个数值不可以使用多次
            if diff in hashmap and hashmap[diff] != idx:
                return [idx, hashmap[diff]]

        return None


# 一遍 hash 表
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# 执行用时: 56 ms, 在Two Sum的Python3提交中击败了68.42% 的用户
# 内存消耗: 14.2 MB, 在Two Sum的Python3提交中击败了0.84% 的用户
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for idx, value in enumerate(nums):
            diff = target - value
            if diff in hashmap:
                return [idx, hashmap[diff]]
            # 不能重复利用这个数组中同样的元素
            # 放在最后是为了保证，在查找哈希表的时候，当前元素刚好不在表中
            hashmap[value] = idx

        return None


# 排序 返回对应的元素 因为顺序变了
# class Solution:
#     def twoSum(self, nums: List[int], target: int) -> List[int]:
#         nums = sorted(nums)
#         l, r = 0, len(nums) - 1
#         while l < r:
#             tmp = nums[l] + nums[r]
#             if tmp == target:
#                 return [nums[l], nums[r]]
#                 break
#             elif tmp < target:
#                 l += 1
#             else:
#                 r -= 1
#         return None

# round 2
