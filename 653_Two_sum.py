# 顺序遍历 + 双指针
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# 输入是一个二叉搜索树
# the inorder traversal of a BST gives the nodes in ascending order
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

# 集合操作
# 时间复杂度 O(n)
# 空间复杂度 O(n)
# Runtime: 92 ms, faster than 83.53% of Python3 online submissions for Two Sum IV - Input is a BST.
# Memory Usage: 15.6 MB, less than 5.00% of Python3 online submissions for Two Sum IV - Input is a BST
class Solution(object):
    def findTarget(self, root: TreeNode, k: int) -> bool:
        return self.find(root, set(), k)
    
    def find(self, node, nodes, k):
        """
        node: 当前节点
        nodes: 已经遍历的节点值
        """
        if not node:
            return False

        if k - node.val in nodes:
            return True
        # 为保证不重复使用，在最后加入集合
        nodes.add(node.val)
        return self.find(node.left, nodes, k) or self.find(node.right, nodes, k)
