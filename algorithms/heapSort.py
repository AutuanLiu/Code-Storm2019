# heapSort 堆排序
# 堆排序是利用堆这种数据结构而设计的一种排序算法，堆排序是一种选择排序，
# 它的最坏，最好，平均时间复杂度均为O(nlogn)，它也是不稳定排序
# 每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；
# 每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆
# 大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]
# 小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]
# 一般升序采用大顶堆，降序采用小顶堆
# a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;
# b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;
# c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序。
# 通常堆是通过一维数组来实现的
# 父节点i的左子节点在位置 (2i+1);
# 父节点i的右子节点在位置 (2i+2);
# 子节点i的父节点在位置 floor((i-1)/2);


def heapSort(lst):
    def shift_down(start, end):
        """最大堆调整"""
        root = start    # 根节点
        while True:
            child = 2 * root + 1    # 左子节点
            if child > end:
                # 如果超出数组的长度就结束循环
                break
            if child + 1 <= end and lst[child] < lst[child + 1]:
                # 存在右子节点并且左子节点小于右子节点，那么最大值的位置就在右子节点，child+1即右子节点（最大值）的位置
                # 找出左右节点的最大值位置
                child += 1
            if lst[root] < lst[child]:
                # 判断根节点和左右子节点的最大值到底谁大
                lst[root], lst[child] = lst[child], lst[root]
                # 最大值提到根节点的位置，同时变更根节点的位置，一般下移一层
                root = child
            else:
                # 否则，即顺序正确，那么就结束循环，当前子树已经调整完毕
                break

    # 创建最大堆
    for start in range((len(lst) - 2) // 2, -1, -1):
        shift_down(start, len(lst) - 1)

    # 堆排序
    for end in range(len(lst) - 1, 0, -1):
        lst[0], lst[end] = lst[end], lst[0]
        # 不调整最后一个元素，因为已经是有序的了
        shift_down(0, end - 1)
    return lst


if __name__ == "__main__":
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20, 25]
    alist1 = [17, 20, 25, 26, 31, 44, 54, 55, 77, 93]
    l = [9, 2, 1, 7, 6, 8, 5, 3, 4]
    l1 = list(range(1000))[::-1]
    alist = heapSort(alist)
    print(alist)
    l = heapSort(l)
    print(l)
    l1 = heapSort(l1)
    print(l1)
    alist = heapSort(alist1)
    print(alist1)
