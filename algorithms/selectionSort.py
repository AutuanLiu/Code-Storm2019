# selectionSort 选择排序
def selectionSort(alist):
    for length in range(len(alist) - 1, 0, -1):
        max_pos = 0
        for first in range(1, length + 1):
            if alist[first] > alist[max_pos]:
                max_pos = first
        # 互换数据
        alist[length], alist[max_pos] = alist[max_pos], alist[length]
    # return alist  # 是否返回时无所谓的


if __name__ == "__main__":
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20, 25]
    alist1 = [17, 20, 25, 26, 31, 44, 54, 55, 77, 93]
    selectionSort(alist)
    print(alist)
    selectionSort(alist1)
    print(alist1)
