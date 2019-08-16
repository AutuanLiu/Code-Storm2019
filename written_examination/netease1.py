# C++ 太麻烦了
# import sys

# if __name__ == '__main__':
#     # 读取第一行的n
#     n = int(sys.stdin.readline().strip())
#     # 读取每一行
#     line = sys.stdin.readline().strip()
#     # 把每一行的数字分隔后转化成int列表
#     values = list(map(int, line.split()))
#     ret = []

#     # 通过观察发现输出的数值和输入的数值的和保持不变 n + 1
#     for item in values:
#         ret.append(str(n + 1 - item))
#     print(" ".join(ret))


# 2
# import sys

# def solution(n, nums):
#     # 特殊情况的处理
#     if n <= 1:
#         return "YES"
#     # 使用双向遍历的方法
#     # forward
#     f = nums[1:] + [nums[0]]
#     # backward
#     b = [nums[n - 1]] + nums[:(n - 1)]
#     # sums
#     sums = [x + y for x, y in zip(f, b)]

#     for x, y in zip(nums, sums):
#         if x > y:
#             return "NO"
#     return "YES"


# if __name__ == '__main__':
#     t = int(sys.stdin.readline().strip())
#     ret = []
#     # 这里有 t 组输入
#     while t:
#         n = int(sys.stdin.readline().strip())
#         nums = [int(t) for t in sys.stdin.readline().strip().split()]
#         ret.append(solution(n, nums))
#         t -= 1
#     print("\n".join(ret))

import sys

def solution(s, t):
    # 特殊情况的处理
    m, n = len(s), len(t)
    if m > n:
        return solution(t, s)
    # 根据动态规划的公式计算
    
    return "YES"

if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    ret = []
    # 这里有 n 组输入
    while n:
        s = sys.stdin.readline().strip()
        t = sys.stdin.readline().strip()
        ret.append(solution(s, t))
        n -= 1
    print("\n".join(ret))