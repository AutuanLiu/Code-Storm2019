# 长度一致
class Solution:
    def __init__(self):
        # 使用列表表示栈结构，列表的尾部表示栈顶
        self.stackInt = []
        self.stackMin = []

    def push(self, node):
        self.stackInt.append(node)
        if len(self.stackMin) <= 0 or node <= self.stackMin[-1]:
            self.stackMin.append(node)
        elif node > self.stackMin[-1]:
            self.stackMin.append(self.stackMin[-1])

    def pop(self):
        if len(self.stackInt) > 0:
            self.stackInt.pop()
            self.stackMin.pop()

    def top(self):
        return self.stackInt[-1]

    def min(self):
        return self.stackMin[-1]


# 长度不一致
class Solution:
    def __init__(self):
        # 使用列表表示栈结构，列表的尾部表示栈顶
        self.stackInt = []
        self.stackMin = []

    def push(self, node):
        self.stackInt.append(node)
        if len(self.stackMin) <= 0 or node <= self.stackMin[-1]:
            self.stackMin.append(node)

    def pop(self):
        if self.stackInt[-1] == self.stackMin[-1]:
            self.stackMin.pop()
        self.stackInt.pop()

    def top(self):
        return self.stackInt[-1]

    def min(self):
        return self.stackMin[-1]
