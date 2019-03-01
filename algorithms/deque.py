# 双向队列实现
# 列表第一个元素作为队尾，最后一个元素作为队首
class Deque:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addRear(self, item):
        self.items.insert(0, item)

    def addFront(self, item):
        self.items.append(item)

    def removeRear(self):
        self.items.pop(0)

    def removeFront(self):
        self.items.pop()

    @property
    def size(self):
        return len(self.items)

    def __repr__(self):
        return f'{[x for x in self.items]}'


if __name__ == "__main__":
    q = Deque()
    q.addFront(4)
    q.addFront('dog')
    q.addFront(True)
    q.addRear(True)
    q.addRear(False)
    print(q.size)
    print(q)
    q.removeFront()
    print(q)
    q.removeRear()
    print(q)
    print(q.size)
