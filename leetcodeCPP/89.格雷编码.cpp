/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 *
 * https://leetcode-cn.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (65.40%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 13.9K
 * Testcase Example:  '2'
 *
 * 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
 * 
 * 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: [0,1,3,2]
 * 解释:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * 对于给定的 n，其格雷编码序列并不唯一。
 * 例如，[0,2,3,1] 也是一个有效的格雷编码序列。
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 示例 2:
 * 
 * 输入: 0
 * 输出: [0]
 * 解释: 我们定义格雷编码序列必须以 0 开头。
 * 给定编码总位数为 n 的格雷编码序列，其长度为 2^n。当 n = 0 时，长度为 2^0 = 1。
 * 因此，当 n = 0 时，其格雷编码序列为 [0]。
 * 
 * 
 */
// 回溯法
// class Solution {
// public:
//     // 这个函数可以使用 stoi("1101", 0, 2) 计算
//     int s2int(string x)
//     {
//         int ret = 0;
//         long long mask = 1;
//         for (auto it = x.rbegin(); it != x.rend(); it++) {
//             ret += (*it - '0') * mask;
//             mask <<= 1;
//         }
//         return ret;
//     }

//     // 如果当前二进制是 0 那下一个分支就是 0, 1
//     // 如果当前二进制是 1 那下一个分支就是 1, 0
//     void getGray(int n, int flag, string str, vector<int>& ret)
//     {
//         // 递归出口
//         if (str.length() == n)
//             // ret.push_back(stoi(str, 0, 2));  // 二进制字符串转整数
//             ret.push_back(s2int(str)); // 二进制字符串转整数
//         else if (flag == 0) {
//             str.push_back('0');
//             getGray(n, 0, str, ret);
//             str.pop_back();
//             str.push_back('1');
//             getGray(n, 1, str, ret);
//         } else {
//             str.push_back('1');
//             getGray(n, 0, str, ret);
//             str.pop_back();
//             str.push_back('0');
//             getGray(n, 1, str, ret);
//         }
//     }

//     vector<int> grayCode(int n)
//     {
//         vector<int> ret;
//         getGray(n, 0, "", ret);
//         return ret;
//     }
// };

// G(n + 1) = G(n) + map(x + x^n, G'(n))
class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret = { 0 }; // 从0开始
        unsigned int mask = 1;
        for (int i = 0; i < n; i++) {
            // 在前一个格雷编码的基础上 逆序加上mask
            int m = ret.size();
            for (int j = m - 1; j >= 0; j--) {
                ret.push_back(mask + ret[j]);
            }
            // 每增加一位 mask * 2 表示在二进制前面加 1 转换为十进制即表示 + mask
            mask <<= 1;
        }
        return ret;
    }
};
