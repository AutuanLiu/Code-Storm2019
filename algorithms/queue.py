# 队列实现
# 列表第一个元素作为队尾，最后一个元素作为队首
class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        self.items.pop()

    @property
    def size(self):
        return len(self.items)

    def __repr__(self):
        return f'{[x for x in self.items]}'


if __name__ == "__main__":
    q = Queue()
    q.enqueue(4)
    q.enqueue('dog')
    q.enqueue(True)
    print(q)
    q.dequeue()
    print(q)
    print(q.size)
