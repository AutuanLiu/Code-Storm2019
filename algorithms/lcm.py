# 最小公倍数
# 公式：lcm(a,b) = a * b / gcd(a,b)

from gcd import gcd


def lcm(a: int, b: int):
    if a == 0 or b == 0:
        return 0
    return a * b / gcd(a, b)


if __name__ == "__main__":
    print(lcm(4, 6))
