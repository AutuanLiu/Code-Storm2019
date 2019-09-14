/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (18.11%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 25.2K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 * 
 * 示例 1:
 * 
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int ret = 0, n = n;
        for (int i = 0; i < n; ++i) {
            int duplicate = 1;
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {
                    ++duplicate;
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++cnt;
                    }
                }
                ret = max(ret, cnt);
            }
            ret = max(ret, duplicate);
        }
        return ret;
    }
};

// 思路：利用哈希表记录两点的差分（dx，dy）的个数，在记录dx和dy的时候，将dx和dy同时除以他们两个的最大公约数，
// 这样斜率相同的点的dx和dy就相同。利用p在记录相同点的个数，最后的结果就是相同点的个数加上斜率相同点的个数。
// 注意：这里用了两次循环，其实每次统计的是包含最外层那个点在内的（即点points[i]），
// 直线上最多的点数。统计的相同的点也是统计和points[i]重合的点，当外循环中的i变化时，p的值重新初始化为1，重新开始统计
class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int ret = 0, n = n;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                int dx = points[j][0] - points[i][1];
                int dy = points[j][0] - points[i][1];
                int d = gcd(dx, dy);
                ++m[{ dx / d, dy / d }];
            }
            ret = max(ret, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                ret = max(ret, it->second + duplicate);
            }
        }
        return ret;
    }
    int gcd(int a, int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        if (n <= 2)
            return n;
        int ret = 2;
        for (int i = 1; i < n; i++) {
            //这里虽然每次找两个相邻点斜率作为基准，只覆盖了n-1个斜率
            //但是下面的for循环每次都遍历所有点，因此所有斜率都覆盖到了
            int x0 = points[i - 1][0], y0 = points[i - 1][1];
            int x1 = points[i][0], y1 = points[i][1];
            int cnt = 0;
            //点重复，遍历一遍，统计一共有多少个重复点，
            // 因为(x0,y0)，和(x1,y1)也会被遍历到，因此统计值不需要+1或+2
            if (x0 == x1 && y0 == y1) {
                for (int j = 0; j < n; j++) {
                    if (points[j][0] == x1 && points[j][1] == y1)
                        cnt++;
                }
            } else { //找三点共线，遍历一遍，因为(x0,y0)，和(x1,y1)也会被遍历到，因此统计值不需要+1或+2
                for (int j = 0; j < n; j++) {
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    //用乘法代替除法避免除数为0 的情况
                    if ((long long)(y2 - y1) * (x1 - x0) == (long long)(x2 - x1) * (y1 - y0))
                        cnt++;
                }
            }
            ret = max(ret, cnt);
        }
        return ret;
    }
};