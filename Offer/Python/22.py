class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        res, queue = [], []
        if root != None:
            queue.insert(0, root)
            while len(queue) > 0:
                root = queue.pop()
                res.append(root.val)
                if root.left != None:
                    queue.insert(0, root.left)
                if root.right != None:
                    queue.insert(0, root.right)
        return res
