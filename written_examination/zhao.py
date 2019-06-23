import sys

def solutions(array, n, m):
    max_v, sums = max(array) + m, 0
    for item in array:
        sums += max_v - item
    if sums <= m:
        min_v = max_v
    else:
        left = (m - sums) // n if (m - sums) % n == 0 else (m - sums) // n + 1
        min_v = max_v + left

    return max_v, min_v


if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    m = int(sys.stdin.readline().strip())
    array = []
    for _ in range(n):
        array.append(int(sys.stdin.readline().strip()))
    max_v, min_v = solutions(array, n, m)
    print(min_v, max_v)
