# sequentialSearch 实现数学搜索 查找元素
def sequentialSearch(seq, item):
    """实现顺序搜索
    
    Args:
        seq (list): 被查找的序列数值
        item (int): 要查找的数值
    """

    found = False
    for t in seq:
        if t == item:
            found = True
    return found


if __name__ == "__main__":
    testlist = [1, 2, 32, 8, 17, 19, 42, 13, 0]
    print(sequentialSearch(testlist, 3))
    print(sequentialSearch(testlist, 13))
