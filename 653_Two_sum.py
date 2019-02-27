# 
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# Runtime: 104 ms, faster than 53.85% of Python3 online submissions for Two Sum IV - Input is a BST.
# Memory Usage: 15.4 MB, less than 5.00% of Python3 online submissions for Two Sum IV - Input is a BST.
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        def inorder(root):
            while root:
                inorder(root.left)
                nums.append(root.val)
                inorder(root.right)
            
        nums = []
        inorder(root)
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] + nums[r] == k:
                return True
            elif nums[l] + nums[r] < k:
                l += 1
            else:
                r -= 1
        return False
