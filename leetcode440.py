import sys


def findKthNumber(n, k):
    from math import log10

    def sumdig(n):
        return 0 if n == 0 else n % 10 + sumdig(n // 10)

    def h(n, m):
        return (10 * n - sumdig(n) - 10**m + 1) // 9 + m

    def kth(k, m):
        G = (10**m - 1) // 9
        x = 1 + (k - 1) // G
        k = (k - 1) % G
        while k != 0:
            G = (G - 1) // 10
            x = 10 * x + (k - 1) // G
            k = (k - 1) % G
        return x

    m = 1 + int(log10(n))

    t = h(n, m)
    if k <= t: return kth(k, m)
    return kth(k - t + h(n // 10, m - 1), m - 1)


if __name__ == '__main__':
    n, k = list(map(int, sys.stdin.readline().strip().split(',')))
    if n >= k:
        res = findKthNumber(n, k)
    print(res)

# if __name__ == '__main__':
#     n, k = list(map(int, sys.stdin.readline().strip().split(',')))
#     if n >= k:
#         res = int(sorted(list(map(str, range(1, n + 1))))[k - 1])
#     print(res)
