# insertionSort 插入排序
def insertionSort(alist):
    for index in range(1, len(alist)):
        cur_value = alist[index]
        pos = index
        while pos > 0 and alist[pos - 1] > cur_value:
            alist[pos] = alist[pos - 1]
            pos -= 1
        alist[pos] = cur_value


if __name__ == "__main__":
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20, 25]
    alist1 = [17, 20, 25, 26, 31, 44, 54, 55, 77, 93]
    insertionSort(alist)
    print(alist)
    insertionSort(alist1)
    print(alist1)
