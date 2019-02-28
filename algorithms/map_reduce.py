from functools import reduce


# 求阶乘
def factorial(n: int) -> int:
    if n == 0:
        return 1
    return reduce(lambda arg1, arg2: arg1 * arg2, range(1, n + 1), 1)


# 求累积和
def comsum(l: list) -> list:
    return reduce(lambda x, y: x + y, l)


# 把序列[1, 3, 5, 7, 9]变换成整数 13579
def func(l: list) -> int:
    return reduce(lambda x, y: 10 * x + y, l)


# 把str转换为int的函数
def str2int(s: str) -> int:
    digit = {str(k): k for k in range(10)}
    for s1 in s:
        if s1 not in digit:
            return
    return reduce(lambda x, y: x * 10 + y, map(lambda x: digit[x], s))


# 把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字。输入：['adam', 'LISA', 'barT']，输出：['Adam', 'Lisa', 'Bart']
def func1(s: list) -> list:
    return list(map(lambda x: x.lower().title(), s))


# str2float
def str2float(s):
    digit = {str(k): k for k in range(10)}
    digit['.'] = -1
    nums = map(lambda ch: digit[ch], s)
    point = 0    # 指示变量，表示是否是小数点

    def to_float(f, n):
        nonlocal point
        if n == -1:
            point = 1    # 更改为小数状态，不做乘法操作，小数点不会该表数值
            return f
        if point == 0:
            # 整数部分
            return f * 10 + n
        else:
            # 小数部分
            point = point * 10
            return f + n / point

    return reduce(to_float, nums, 0.0)


if __name__ == "__main__":
    fact = [factorial(x) for x in [0, 1, 3, 5, 7, 9]]
    com1 = comsum([0, 1, 3, 5, 7, 9])
    f1 = func([0, 1, 3, 5, 7, 9])
    print(fact, com1, f1, str2int('13579'), str2int('13b79'), int('13579'), str(13579), func1(['adam', 'LISA', 'barT']), sep='\n')
    print(str2float('0'))
    print(str2float('123.456'))
    print(str2float('123.45600'))
    print(str2float('0.1234'))
    print(str2float('.1234'))
    print(str2float('120.0034'))
    print(str2float('.'))
    print(str2float('123.'))
