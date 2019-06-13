class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        if not root or root.val > expectNumber:
            return []

        if not root.left and not root.right and root.val == expectNumber:
            return [[root.val]]
        else:
            expectNumber -= root.val
            left = self.FindPath(root.left, expectNumber)
            right = self.FindPath(root.right, expectNumber)

            result = [[root.val] + i for i in left]
            for i in right:
                result.append([root.val] + i)

        return sorted(result, key=lambda x: -len(x))
