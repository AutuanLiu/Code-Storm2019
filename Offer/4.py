class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# 由前序和中序构建二叉树
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        if not pre or not tin:
            return None
        root = TreeNode(pre[0])    # 前向遍历的第一个元素为根节点
        # 前序遍历和中序遍历不匹配
        if set(pre) != set(tin):
            return None
        i = tin.index(pre[0])    # 根节点所在的中序遍历的位置
        # 先序：根左右
        # 中序：左根右
        root.left = self.reConstructBinaryTree(pre[1:i + 1], tin[:i])
        root.right = self.reConstructBinaryTree(pre[i + 1:], tin[i + 1:])
        return root


# 由后序和中序构建二叉树
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, post, tin):
        if not post or not tin:
            return None
        root = TreeNode(post[-1])    # 后向遍历的最后一个元素为根节点
        # 后序遍历和中序遍历不匹配
        if set(post) != set(tin):
            return None
        i = tin.index(post[-1])    # 根节点所在的中序遍历的位置
        # 后序：左右根
        # 中序：左根右
        root.left = self.reConstructBinaryTree(post[:i], tin[:i])
        root.right = self.reConstructBinaryTree(post[i - 1:-1], tin[i + 1:])
        return root
