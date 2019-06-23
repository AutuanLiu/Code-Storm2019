import sys


def solution(array):
    """
    ret = max{a[i] + a[j] + i - j} = max{a[i] + i} + max{a[j] - j}
    """

    # 假设 第一个观光点是 0
    ret, aii = 0, 0
    for j, aj in enumerate(array):
        # max{a[j] - j}
        ret = max(ret, aj - j + aii)
        # max{a[i] + i}
        aii = max(aii, aj + j)
    return ret


if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    array = [int(x) for x in sys.stdin.readline().strip().split()]
    ret = solution(array)
    print(ret)