# shellSort 希尔排序
def shellSort(alist):
    sublistcount = len(alist) // 2    # 间隔为 2 的子序列的个数
    # 对于每个子序列执行插入排序
    while sublistcount > 0:
        for startposition in range(sublistcount):
            gapInsertionSort(alist, startposition, sublistcount)
        print("After increments of size", sublistcount, "The list is", alist)
        sublistcount = sublistcount // 2    # 子序列的长度


def gapInsertionSort(alist, start, gap):
    for index in range(start + gap, len(alist), gap):
        currentvalue = alist[index]
        position = index
        while position >= gap and alist[position - gap] > currentvalue:
            alist[position] = alist[position - gap]
            position = position - gap
        alist[position] = currentvalue


if __name__ == "__main__":
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20, 25]
    alist1 = [17, 20, 25, 26, 31, 44, 54, 55, 77, 93]
    shellSort(alist)
    print(alist)
    shellSort(alist1)
    print(alist1)
