def f(A, B, R):
    m, n = len(A), len(B)
    ret = []
    pm = float('inf')
    t = None
    for i in range(m):
        for j in range(n):
            p = B[j] - A[i]
            if p == R:
                ret.append(",".join([str(A[i]), str(B[j])]))
            p = -p if p < 0 else p
            if p < pm:
                t = ",".join([str(A[i]), str(B[j])])
    if len(ret) == 0:
        ret = t
    return ret


def g(A):
    ln = len(A)
    B = []
    for i in range(ln):
        if i == 0:
            B.append(int(A[i][1:]))
        elif i == ln - 1:
            B.append(int(A[i][:-1]))
        else:
            B.append(int(A[i]))
    return B


if __name__ == "__main__":
    s = input()
    s = s.split("=")[1:]
    A, B, R = s
    A = A[:-2].split(',')
    B = B[:-2].split(',')
    R = int(R)
    C = f(g(A), g(B), R)
    C = ['(' + x + ')' for x in C]
    print("".join(C))