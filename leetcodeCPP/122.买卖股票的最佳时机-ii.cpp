/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (54.58%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    66.9K
 * Total Submissions: 122.5K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [7,1,5,3,6,4]
 * 输出: 7
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4,5]
 * 输出: 4
 * 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 */
// 把连续的峰谷高度加起来
// 因为 一旦出现多个峰谷，其和总是大于单个峰谷的高度
// 单间区域和单增区域
// class Solution {
// public:
//     int maxProfit(vector<int>& prices)
//     {
//         if (prices.empty())
//             return 0;
//         int ret = 0, n = prices.size();
//         int buy = prices[0], sell = prices[0], start = 0;
//         // 索引必须小于 n - 1 最大取值是 n-2 保证索引有效
//         while (start < n - 1) {
//             // 找到谷
//             for (; start < n - 1 && prices[start] >= prices[start + 1]; start++)
//                 ;
//             buy = prices[start];

//             // 找到峰
//             for (; start < n - 1 && prices[start] <= prices[start + 1]; start++)
//                 ;
//             sell = prices[start];

//             // 求和 并进行下一个峰谷的寻找
//             ret += sell - buy;
//         }
//         return ret;
//     }
// };

// 把所有的单增区间加起来即可
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ret = 0, n = prices.size();
        for (int i = 0; i < n - 1; i++) {
            if (prices[i] < prices[i + 1])
                ret += prices[i + 1] - prices[i];
        }
        return ret;
    }
};
