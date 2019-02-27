# 最大公约数-递归形式
def gcd(a: int, b: int):
    # if b == 0:
    #     return a
    # else:
    #     return gcd(b, a % b)
    return a if b == 0 else gcd(b, a % b)


gcd2 = lambda a, b: a if b == 0 else gcd2(b, a % b)


# 最大公约数-非递归形式
def gcd1(a: int, b: int):
    while b != 0:
        t = a % b
        a = b
        b = t
    return a


if __name__ == "__main__":
    test = [[2, 8], [4, 6], [3, 12], [15, 35]]
    for func in [gcd, gcd1, gcd2]:
        for args in test:
            print(func(*args))
