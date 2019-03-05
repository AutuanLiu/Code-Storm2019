// in-place 操作
// 从后往前 O(n)
class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        // 判断特殊情况
        if (str == nullptr || length <= 0)
            return;
        int newlen = 0;
        int oldlen = 0;
        // 统计原字符串和新字符串的长度
        int j = 0;  // 从头开始
        while (str[j] != '\0')
        {
            newlen++;
            oldlen++;
            if (str[j] == ' ')
                newlen += 2;
            j++;
        }
        // 新长度大于总长度
        if (newlen > length || newlen == oldlen)
            return;
        str[newlen] = '\0';  // 以 '\0' 结束字符串
        // 两个指针
        for (int i = oldlen - 1, j = newlen - 1; i >= 0; i--, j--)
        {
            if (str[i] == ' ')
            {
                str[j] = '0';
                str[j - 1] = '2';
                str[j - 2] = '%';
                j = j - 2;
            }
            else
                str[j] = str[i];  // 复制移动
        }
    }
};
