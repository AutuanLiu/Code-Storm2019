# binarySearch 有序列表的二分搜索
def binarySearch(alist, item):
    left, right = 0, len(alist) - 1
    while len(alist) > 0 and left <= right:
        mid = (left + right) // 2
        if alist[mid] == item:
            return True
        elif alist[mid] > item:
            right = mid - 1
        else:
            left = mid + 1
    return False


# 递归实现
def binarySearch1(alist, item):
    if len(alist) > 0:
        mid = len(alist) // 2
        if alist[mid] == item:
            return True
        elif alist[mid] < item:
            return binarySearch(alist[(mid + 1):], item)
        else:
            return binarySearch(alist[:(mid - 1)], item)
    return False


if __name__ == "__main__":
    testlist = [0, 1, 2, 8, 13, 17, 42]
    testlist1 = [1]
    testlist2 = []
    print(binarySearch(testlist, 3))
    print(binarySearch(testlist, 13))
    print(binarySearch(testlist1, 1))
    print(binarySearch1(testlist, 3))
    print(binarySearch1(testlist, 13))
    print(binarySearch1(testlist1, 1))
    print(binarySearch1(testlist2, 1))
