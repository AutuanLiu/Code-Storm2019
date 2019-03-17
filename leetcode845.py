import sys


def longestMountain(A):
    N = len(A)
    ans = base = 0

    while base < N:
        end = base
        if end + 1 < N and A[end] < A[end + 1]:
            while end + 1 < N and A[end] < A[end + 1]:
                end += 1

            if end + 1 < N and A[end] > A[end + 1]:
                while end + 1 < N and A[end] > A[end + 1]:
                    end += 1
                ans = max(ans, end - base + 1)

        base = max(end, base + 1)

    return ans


if __name__ == '__main__':
    n = list(map(int, sys.stdin.readline().strip().split(',')))
    if len(n) >= 3:
        res = longestMountain(n)
    print(res)
