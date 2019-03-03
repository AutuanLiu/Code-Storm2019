# quick sort 快速排序
# def quickSort(alist):
def quick_sort_inplace(lst):
    """原地操作，不需要开辟空间"""

    def partition(lst, start, end):
        """找到分割点的同时进行排序"""
        i = start - 1
        pivot = lst[end]    # 使用最后的一个元素作为分割元素
        for j in range(start, end):
            if lst[j] < pivot:
                i = i + 1
                # 如果找到比基准元素小的就交换
                lst[i], lst[j] = lst[j], lst[i]
        # 遍历一遍即以找到基准位置 i+1, 之后填入基准元素
        lst[i + 1], lst[end] = lst[end], lst[i + 1]
        return i + 1

    def sort(lst, start, end):
        if start < end:
            p = partition(lst, start, end)    # 找到分割位置
            sort(lst, start, p - 1)    # 左半边排序
            sort(lst, p + 1, end)    # 右半边排序

    sort(lst, 0, len(lst) - 1)    # 排序
    return lst    # 原地操作，可以不用返回


def quick_sort1(lst):
    """递归过程"""
    if len(lst) <= 1:
        return lst
    less = []
    greater = []
    pivot = lst.pop()    # 以最后一个元素作为基准元素并取出
    for item in lst:
        if item < pivot:
            less.append(item)
        else:
            greater.append(item)
    lst.append(pivot)    # 不要改变 lst
    return quick_sort1(less) + [pivot] + quick_sort1(greater)


def quickSort(alist):
    """两个指针版本"""

    def partition(alist, start, end):
        pivot = alist[start]    # 以开始元素作为基准元素
        left, right = start, end
        while left != right:
            # 循环一直到left==right 此时左右指针相遇便找到了基准的位置
            while alist[right] >= pivot and left < right:
                right -= 1
            while alist[left] <= pivot and left < right:
                left += 1
            alist[left], alist[right] = alist[right], alist[left]
        alist[left], alist[start] = pivot, alist[left]
        return left

    def sort(alist, start, end):
        if start < end:
            p = partition(alist, start, end)
            sort(alist, start, p - 1)
            sort(alist, p + 1, end)

    sort(alist, 0, len(alist) - 1)
    return alist


if __name__ == "__main__":
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20, 25, 78, 12, 234]
    alist1 = [17, 20, 25, 26, 31, 44, 54, 55, 77, 93]
    blist = quick_sort_inplace(alist)
    print(blist)
    blist = quick_sort_inplace(alist1)
    print(blist)
    blist = quick_sort1(alist)
    print(blist)
    blist = quick_sort1(alist1)
    print(blist)
    blist = quickSort(alist)
    print(blist)
    blist = quickSort(alist1)
    print(blist)
