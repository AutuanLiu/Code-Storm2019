class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 递归
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        if not root or (not root.left and not root.right):
            return root
        root.left, root.right = root.right, root.left
        self.Mirror(root.left)
        self.Mirror(root.right)

# 队列
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        if not root or (not root.left and not root.right):
            return root
        queue = [root]
        while len(queue) > 0:
            p = queue.pop()
            p.left, p.right = p.right, p.left
            if p.left:
                queue.insert(0, p.left)
            if p.right:
                queue.insert(0, p.right)
