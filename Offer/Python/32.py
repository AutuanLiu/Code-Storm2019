# 每一个和后面的进行比较，将小的放在前面
# 类似于冒泡排序，每一轮将最小的放在前面（高位）这样保证数值最小
class Solution:
    def PrintMinNumber(self, numbers):
        if not numbers:
            return ''

        str_num = [str(m) for m in numbers]
        for i in range(len(numbers) - 1):
            for j in range(i + 1, len(numbers)):
                if str_num[i] + str_num[j] > str_num[j] + str_num[i]:
                    str_num[i], str_num[j] = str_num[j], str_num[i]

        return ''.join(str_num)

if __name__ == '__main__':
    s = Solution()
    x = [3, 32, 321]
    y = s.PrintMinNumber(x)
    print(y)
