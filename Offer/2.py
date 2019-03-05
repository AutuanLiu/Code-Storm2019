# 使用 list 实现
class Solution:
    def replaceSpace(self, s):
        if s == '' or not isinstance(s, str):
            return ''
        s_list = list(s)
        new_str = []
        for item in s_list:
            if item == ' ':
                new_str.extend('%20')
            else:
                new_str.append(item)
        return ''.join(new_str)


# 使用从后向前的遍历
class Solution:
    def replaceSpace(self, s):
        if s == '' or not isinstance(s, str):
            return ''
        new_len = 0
        for item in s:
            if item == ' ':
                new_len += 2
            new_len += 1
        new_list = new_len * [None]
        j = new_len - 1
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ':
                new_list[j] = '0'
                new_list[j - 1] = '2'
                new_list[j - 2] = '%'
                j -= 3
                i -= 1
            else:
                new_list[j] = s[i]
                j -= 1
                i -= 1
        return ''.join(new_list)
