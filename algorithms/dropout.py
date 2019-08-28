import numpy as np


def dropout(X, drop_prob, phrase='traing'):
    if not phrase == 'traing':
        return X
    assert 0 <= drop_prob <= 1
    # 不做改变
    if drop_prob == 0:
        return X
    # 这种情况下把全部元素都丢弃
    if drop_prob == 1:
        return X.zeros_like()
    keep_prob = 1 - drop_prob
    mask = np.random.uniform(0, 1, X.shape) < keep_prob
    return mask * X / keep_prob


def dropout(X, drop_prob, phrase == 'traing'):
    if not phrase == 'traing':
        return X
    assert 0 < drop_prob < 1
    keep_prob = 1 - drop_prob
    # 大于 keep_prob 的概率无法达到
    mask = np.random.uniform(0, 1, X.shape) < keep_prob
    return mask * X / keep_prob

if __name__ == "__main__":
    X = np.random.randn(5, 5)
    new_X = dropout(X, 0.5)
    print(new_X)
