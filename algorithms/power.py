# 二分幂法 求x^n
# x^n = x^(n/2) * x^(n/2) if n is even else x^((n-1)/2)*x^((n-1)/2)*x
def power_func(x, n: int):
    ans = 1.0
    while n != 0:
        if n % 2 == 1:
            ans *= x
        x *= x
        n //= 2
    return ans


# 递归法 求x^n
def power_func1(x, n: int):
    ans = 1.0
    if n == 0:
        return 1
    else:
        return x * power_func1(x, n - 1)


# 循环法 求x^n
def power_func2(x, n: int):
    ans = 1.0
    while n != 0:
        ans *= x
        n -= 1
    return ans


if __name__ == "__main__":
    test = [[2, 3], [4, 5], [3, 3], [5, 3]]
    for func in [power_func, power_func1, power_func2]:
        for args in test:
            print(func(*args))
