from heapq import *


def heapSort(iterable):
    h = []
    for value in iterable:
        heappush(h, value)
    return [heappop(h) for i in range(len(h))]


if __name__ == "__main__":
    print(heapSort([1, 3, 5, 9, 2]))
