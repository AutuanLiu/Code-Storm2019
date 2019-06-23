import sys


def dfs(array, i, j, visited):
    # 异常判断
    if 0 <= i < len(array) and 0 <= j < len(array[0]):
        if array[i][j] and not visited[i][j]:
            visited[i][j] = 1
            # v1 = [0, 1, -1]
            # 访问不同位置
            dfs(array, i - 1, j - 1, visited)
            dfs(array, i - 1, j, visited)
            dfs(array, i - 1, j + 1, visited)
            dfs(array, i, j - 1, visited)
            dfs(array, i, j + 1, visited)
            dfs(array, i + 1, j - 1, visited)
            dfs(array, i + 1, j, visited)
            dfs(array, i + 1, j + 1, visited)
            return True
    return False


if __name__ == '__main__':
    N, M = [int(x) for x in sys.stdin.readline().strip().split()]
    array = []
    for _ in range(N):
        array.append([int(x) for x in sys.stdin.readline().strip().split()])
    visited, ret = [[0] * M for _ in range(N)], 0
    for i in range(N):
        for j in range(M):
            ret = ret + 1 if dfs(array, i, j, visited) else ret
    print(ret)
