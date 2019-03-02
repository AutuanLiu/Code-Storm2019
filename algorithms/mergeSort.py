# mergeSort 归并排序
# 归并是这样一个过程：把两个排序好了的列表结合在一起组合成一个单一的，有序的新列表。
# 归并排序是一个递归过程
def mergeSort(alist):
    print("Splitting ", alist)
    if len(alist) > 1:
        mid = len(alist) // 2
        lefthalf = alist[:mid]    # 左半边列表
        righthalf = alist[mid:]    # 右半边列表

        mergeSort(lefthalf)
        mergeSort(righthalf)

        i = 0
        j = 0
        k = 0    # 构造新列表
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k] = lefthalf[i]
                i = i + 1
            else:
                alist[k] = righthalf[j]
                j = j + 1
            k = k + 1

        while i < len(lefthalf):
            alist[k] = lefthalf[i]
            i = i + 1
            k = k + 1

        while j < len(righthalf):
            alist[k] = righthalf[j]
            j = j + 1
            k = k + 1
    print("Merging ", alist)


if __name__ == "__main__":
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20, 25]
    alist1 = [17, 20, 25, 26, 31, 44, 54, 55, 77, 93]
    mergeSort(alist)
    print(alist)
    mergeSort(alist1)
    print(alist1)
