# bubbleSort 冒泡排序
def bubbleSort(alist):
    for last in range(len(alist) - 1, 0, -1):
        for first in range(last):
            if alist[first] > alist[first + 1]:
                alist[first], alist[first + 1] = alist[first + 1], alist[first]


def shortBubbleSort(alist):
    """短路冒泡排序"""
    exchange = True    # 状态位
    length = len(alist) - 1
    while length > 0 and exchange:
        exchange = False
        for first in range(length):
            if alist[first] > alist[first + 1]:
                alist[first], alist[first + 1] = alist[first + 1], alist[first]
                exchange = True
        length -= 1


if __name__ == "__main__":
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20, 25]
    alist1 = [17, 20, 25, 26, 31, 44, 54, 55, 77, 93]
    bubbleSort(alist)
    print(alist)
    shortBubbleSort(alist)
    print(alist)
    bubbleSort(alist1)
    print(alist1)
    shortBubbleSort(alist1)
    print(alist1)
