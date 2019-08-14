/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (38.43%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 21.5K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [3,3,5,0,0,3,1,4]
 * 输出: 6
 * 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
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
 * 示例 3:
 * 
 * 输入: [7,6,4,3,1] 
 * 输出: 0 
 * 解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
 * 
 */
// 假设存在一个点 pivot 该点前后各进行一次交易或者只完成一次交易
// pivot 的取值是 1~n-1
// 所以分别从前往后计算最大利益和从后往前计算最大利益
// class Solution {
// public:
//     int getMaxProfit(vector<int>& prices, int start, int end)
//     {
//         int minPrice = INT_MAX, ret = 0, n = prices.size();
//         for (int i = start; i <= end; i++) {
//             minPrice = min(minPrice, prices[i]);
//             ret = max(ret, prices[i] - minPrice);
//         }
//         return ret;
//     }

//     int maxProfit(vector<int>& prices)
//     {
//         int n = prices.size(), ret = 0;
//         // 无法完成交易
//         if (n < 2)
//             return 0;
//         // 最多完成两笔交易
//         for (int pivot = 1; pivot <= n - 1; pivot++) {
//             int tmp = getMaxProfit(prices, 0, pivot - 1) + getMaxProfit(prices, pivot - 1, n - 1);
//             ret = max(ret, tmp);
//         }
//         return ret;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        vector<int> ret(4, 0);
        ret[0] = INT_MIN;
        ret[2] = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            ret[3] = max(ret[3], ret[2] + prices[i]); // Transaction 2: sell
            ret[2] = max(ret[2], ret[1] - prices[i]); // Transaction 2: buy
            ret[1] = max(ret[1], ret[0] + prices[i]); // Transaction 1: sell
            ret[0] = max(ret[0], -prices[i]);         // Transaction 1: buy
        }
        return max(ret[1], ret[3]);
    }
};
