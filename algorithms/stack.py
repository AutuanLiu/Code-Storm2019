# 栈实现
# 列表第一个元素作为栈底，最后一个元素作为栈顶
class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)
    
    def peek(self):
        return self.items[-1]

    def pop(self):
        self.items.pop()

    @property
    def size(self):
        return len(self.items)

    def __repr__(self):
        return f'{[x for x in self.items]}'


if __name__ == "__main__":
    q = Stack()
    q.push(4)
    q.push('dog')
    q.push(True)
    print(q)
    q.pop()
    print(q)
    print(q.size)
