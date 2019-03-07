# 双指针
class Solution:
    def reOrderArray(self, array):
        if len(array) > 0:
            for i in range(len(array)):
                for j in range(len(array) - 1, i, -1):
                    if (array[j] & 1 and not array[j - 1] & 1):
                        array[j], array[j - 1] = array[j - 1], array[j]
        return array


if __name__ == '__main__':
    s = Solution()
    k = [1, 2, 3, 4, 5]
    t = s.reOrderArray(k)
    print(t)
