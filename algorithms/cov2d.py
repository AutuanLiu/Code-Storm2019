import numpy as np


def cov2d(X, K):
    """二维卷积
    X 为输入，K为卷积核
    """

    h, w = K.shape
    Y = np.zeros((X.shape[0] - h + 1, X.shape[1] - w + 1))
    for i in range(Y.shape[0]):
        for j in range(Y.shape[1]):
            Y[i, j] = (X[i: i + h, j: j + w] * K).sum()
    return Y


if __name__ == "__main__":
    X = np.random.randn(8, 8)
    K = np.random.randn(3, 3)
    Z = cov2d(X, K)
    print(Z)
