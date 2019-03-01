# 实现链表结构
# None 表示没有下一个节点
# 判断链表是否为空，只需要判断其头结点是否是 None（接地）
# 不要吝啬 else 想清楚逻辑结构
class Node:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None

    def getData(self):
        return self.data

    def setData(self, newData):
        self.data = newData

    def getNext(self):
        return self.next

    def setNext(self, newNode):
        self.next = newNode


class UnorderList:
    """数值没有大小顺序的一类列表
    """

    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head == None

    def add(self, item):
        newNode = Node(item)
        newNode.setNext(self.head)
        self.head = newNode

    def size(self):
        current = self.head
        count = 0
        while current != None:
            count += 1
            current = current.getNext()
        return count

    def search(self, item):
        current = self.head
        while current != None:
            if current.getData() == item:
                return True
            else:
                # 只有不相等的时候才向后移动指针
                current = current.getNext()
        return False

    def remove(self, item):
        current = self.head
        previous = None
        found = False
        while not found:
            if current.getData() == item:
                found = True
            else:
                # 注意以下两步的顺序
                # 只有不相等的时候才移动
                previous = current
                current = current.getNext()
        if previous == None:
            # 处理删除第一个节点的情况
            self.head = current.getNext()
        elif current == None:
            # 处理删除最后一个节点的情况
            previous.setNext(None)
        else:
            previous.setNext(current.getNext())

    def append(self, item):
        newNode = Node(item)
        current = self.head
        while current.getNext() != None:
            current = current.getNext()
        current.setNext(newNode)

    def __repr__(self):
        current = self.head
        s = 'Linked List: '
        while current != None:
            s += f'{current.getData()} -> '
            current = current.getNext()
        return s[:-4]


if __name__ == "__main__":
    l1 = [31, 77, 17, 93, 26, 54]
    uol = UnorderList()
    for i in l1:
        uol.add(i)
    print(uol)
    print(uol.search(54))
    print(uol.search(18))
    uol.remove(17)
    print(uol)
    uol.remove(54)
    print(uol)
    uol.remove(31)
    print(uol)
    uol.append(88)
    print(uol)
