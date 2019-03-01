def dpMakeChange(coinValueList, change):
    minCoins = {}

    for cents in range(change + 1):
        #cents小于等于1时，coinCount会为空，没法执行min。
        #因此这里先填上
        if cents <= 1:
            minCoins[cents] = cents
            continue
        #遍历cents的每个最优子结构并且添加到list中，等待筛选
        coinCount = [minCoins[cents - j] + 1 for j in coinValueList if cents >= j]
        minCoins[cents] = min(coinCount)
    return minCoins[change]


if __name__ == "__main__":
    result = dpMakeChange([1, 5, 10, 21, 25], 63)
    print(result)
