// in-place 操作
// 从后往前 O(n)
// class Solution
// {
//   public:
//     void replaceSpace(char *str, int length)
//     {
//         // 判断特殊情况
//         if (str == nullptr || length <= 0)
//             return;
//         int newlen = 0;
//         int oldlen = 0;
//         // 统计原字符串和新字符串的长度
//         int j = 0;  // 从头开始
//         while (str[j] != '\0')
//         {
//             newlen++;
//             oldlen++;
//             if (str[j] == ' ')
//                 newlen += 2;
//             j++;
//         }
//         // 新长度大于总长度
//         if (newlen > length || newlen == oldlen)
//             return;
//         str[newlen] = '\0';  // 以 '\0' 结束字符串
//         // 两个指针
//         for (int i = oldlen - 1, j = newlen - 1; i >= 0; i--, j--)
//         {
//             if (str[i] == ' ')
//             {
//                 str[j] = '0';
//                 str[j - 1] = '2';
//                 str[j - 2] = '%';
//                 j = j - 2;
//             }
//             else
//                 str[j] = str[i];  // 复制移动
//         }
//     }
// };

// 替换 str 中的空格为 %20
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string str)
    {
        if (str.empty())
            return str;
        int n = str.length(), nspace = 0;
        // 统计空格字符的个数
        for (int i = 0; i < n; i++) {
            if (str[i] == ' ')
                nspace++;
        }

        if (nspace == 0)
            return str;
        int newlen = n + 2 * nspace;
        string newstr(newlen, ' ');
        for (int i = n - 1, j = newlen - 1; i >= 0; i--) {
            if (str[i] != ' ') {
                newstr[j--] = str[i];
            } else {
                newstr[j--] = '0';
                newstr[j--] = '2';
                newstr[j--] = '%';
            }
        }
        return newstr;
    }
};

int main(void)
{
    string old = "We are happy.";
    string ret = Solution().replaceSpace(old);
    cout << ret << endl;
    return 0;
}
