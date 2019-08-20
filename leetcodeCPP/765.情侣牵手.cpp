/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 *
 * https://leetcode-cn.com/problems/couples-holding-hands/description/
 *
 * algorithms
 * Hard (53.19%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    1.5K
 * Total Submissions: 2.9K
 * Testcase Example:  '[0,2,1,3]'
 *
 * N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。
 * 一次交换可选择任意两人，让他们站起来交换座位。
 * 
 * 人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2,
 * 2N-1)。
 * 
 * 这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。
 * 
 * 示例 1:
 * 
 * 
 * 输入: row = [0, 2, 1, 3]
 * 输出: 1
 * 解释: 我们只需要交换row[1]和row[2]的位置即可。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: row = [3, 2, 0, 1]
 * 输出: 0
 * 解释: 无需交换座位，所有的情侣都已经可以手牵手了。
 * 
 * 
 * 说明:
 * 
 * 
 * len(row) 是偶数且数值在 [4, 60]范围内。
 * 可以保证row 是序列 0...len(row)-1 的一个全排列。
 * 
 * 
 */
// class Solution {
// public:
//     inline int get_couple(int x)
//     {
//         return (x & 1) ? x - 1 : x + 1;
//     }

//     inline int findidx(vector<int>& row, int start, int n, int target)
//     {
//         int idx = start;
//         for (; idx < n && row[idx] != target; idx++) {
//         }
//         return idx;
//     }

//     int minSwapsCouples(vector<int>& row)
//     {
//         int ret = 0, n = row.size();

//         // 固定偶数位置 贪心
//         for (int i = 0; i < n; i += 2) {
//             int couple = get_couple(row[i]); // 找到其配偶
//             // 找到配偶并交换
//             if (couple != row[i + 1]) {
//                 int idx = findidx(row, i + 1, n, couple);
//                 swap(row[i + 1], row[idx]);
//                 ret++;
//             }
//         }
//         return ret;
//     }
// };

// class Solution {
// public:
//     int minSwapsCouples(vector<int>& row)
//     {
//         int ret = 0, N = row.size();

//         vector<int> ptn(N, 0);
//         vector<int> pos(N, 0);

//         for (int i = 0; i < N; i++) {
//             ptn[i] = (i % 2 == 0 ? i + 1 : i - 1);
//             pos[row[i]] = i;
//         }

//         for (int i = 0; i < N; i++) {
//             for (int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]) {
//                 swap(row[i], row[j]);
//                 swap(pos[row[i]], pos[row[j]]);
//                 ret++;
//             }
//         }

//         return ret;
//     }
// };

// 并査集
class Solution {
public:
    vector<int> parent, size;

    int find(int x)
    {
        return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }

    void uni(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (size[fx] < size[fy]) {
                parent[fx] = fy;
                size[fy] += size[fx];
            } else {
                parent[fy] = fx;
                size[fx] += size[fy];
            }
        }
    }

    int minSwapsCouples(vector<int>& row)
    {
        int n = row.size(), m = n / 2, ret = 0;
        parent = vector<int>(m, 0), size = vector<int>(m, 1);
        // 构造初始并査集
        for (int i = 0; i < m; i++)
            parent[i] = i;

        // 合并
        for (int i = 0; i < n; i += 2) {
            int x = row[i] >> 1, y = row[i + 1] >> 1;
            // 情侣的特征 除以2相等
            // 如果相邻的元素不是情侣，那么就合并
            if (find(x) != find(y)) {
                uni(x, y);
                ret++;
            }
        }
        return ret;
    }
};