# 二叉树中序遍历的 生成器写法
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def mid_order(root):
    if not root: return
    yield from mid_order(root.left)
    yield root.val
    yield from mid_order(root.right)
