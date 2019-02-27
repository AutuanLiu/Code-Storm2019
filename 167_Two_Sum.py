# https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
# 关键条件
# 按照升序排列 的有序数组
# 返回的下标值（index1 和 index2）不是从零开始的。
# 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素
# 
# 暴力解决
# 时间复杂度 O(n^2)
# 空间复杂度 O(n)
# 超时
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        length = len(numbers)
        for idx, value in enumerate(numbers):
            diff = target - value
            # 升序排列，如果差值小于当前数值，则停止搜索
            # 两个数值可以相等，所以是小于
            if diff < value:
                return None
            # 保证不重复使用同一个位置的数值两次
            for idx1 in range(idx + 1, length):
                if numbers[idx1] == diff:
                    # 返回数字所在的位置，从1开始
                    return [idx + 1, idx1 + 1]
        return None

# 两遍哈希表
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# 执行用时: 72 ms, 在Two Sum II - Input array is sorted的Python3提交中击败了15.39% 的用户
# 内存消耗: 13.5 MB, 在Two Sum II - Input array is sorted的Python3提交中击败了0.90% 的用户
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hashtable = {}
        # 构建哈希表
        for idx, value in enumerate(numbers):
            hashtable[value] = idx + 1
        for idx, value in enumerate(numbers):
            diff = target - value
            # 升序排列
            # 不可重复使用数值
            # diff >= value 所有的值均已保存
            if diff >= value and diff in hashtable and hashtable[diff] != idx:
                # 返回数字所在的位置, 从1开始
                return [idx + 1, hashtable[diff]]
        return None

# 一遍哈希表
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# 执行用时: 72 ms, 在Two Sum II - Input array is sorted的Python3提交中击败了15.39% 的用户
# 内存消耗: 13.7 MB, 在Two Sum II - Input array is sorted的Python3提交中击败了0.90% 的用户
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hashtable = {}
        for idx, value in enumerate(numbers):
            diff = target - value
            # 考虑升序排列的条件
            if diff in hashtable:
                return sorted([idx + 1, hashtable[diff]])
            # 同一个数值不可使用两次，所以，放在后边，保证搜索的时候，不包括当前数值
            hashtable[value] = idx + 1
        return None

# 双指针（数据序列本身有序）
# 时间复杂度 O(n)
# 空间复杂度 O(1)
# Runtime: 48 ms, faster than 43.45% of Python3 online submissions for Two Sum II - Input array is sorted.
# Memory Usage: 13.7 MB, less than 5.14% of Python3 online submissions for Two Sum II - Input array is sorted.
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        # l < r, 排除 len(numbers)==1的情况
        while l < r:
            s = numbers[l] + numbers[r]
            if s == target:
                return [l + 1, r + 1]
            elif s < target:
                l += 1
            else:
                r -= 1
        return None

# 二分搜索
# 时间复杂度 O(n)
# 空间复杂度 O(1)
# Runtime: 72 ms, faster than 17.01% of Python3 online submissions for Two Sum II - Input array is sorted.
# Memory Usage: 13.5 MB, less than 5.14% of Python3 online submissions for Two Sum II - Input array is sorted.
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        length = len(numbers)
        for idx in range(length):
            l, r = idx+1, length-1
            tmp = target - numbers[idx]
            while l <= r:
                mid = l + (r-l)//2
                if numbers[mid] == tmp:
                    return [idx+1, mid+1]
                elif numbers[mid] < tmp:
                    l = mid+1
                else:
                    r = mid-1
        return None
