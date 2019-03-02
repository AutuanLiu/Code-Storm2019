# bankSort 桶排序
def bankSort(alist):
    bank = [0] * (max(alist) + 1)
    blist = alist
    for t in alist:
        bank[t] += 1
    num = 0
    for idx in range(len(bank)):
        while bank[idx] != 0:
            blist[num] = idx
            bank[idx] -= 1
            num += 1
    return blist



if __name__ == "__main__":
    alist = [54, 25, 93, 17, 77, 31, 44, 55, 20, 25]
    alist1 = [17, 20, 25, 25, 31, 44, 54, 55, 77, 93]
    blist = bankSort(alist)
    print(blist)
    blist = bankSort(alist1)
    print(blist)