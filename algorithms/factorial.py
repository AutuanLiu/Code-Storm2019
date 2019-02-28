# 求阶乘的 预处理法
# 递归
def factorial(a: int):
    if a == 0:
        return 1
    return a * factorial(a - 1)


# 非递归 + 字典
def factorial1(a: int):
    c = {0: 1}
    for i in range(1, a + 1):
        c[i] = i * c[i - 1]
    return c[a]


if __name__ == "__main__":
    test = [5, 6, 7, 8]
    for func in [factorial, factorial1]:
        for args in test:
            print(func(args))
