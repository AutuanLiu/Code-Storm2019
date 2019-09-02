def softmax(x):
    exps = np.exp(x)
    return exps / np.sum(exps)


# 指数可能会超出表示范围
def softmax1(x):
    exps = np.exp(x - np.max(x))
    return exps / np.sum(exps)