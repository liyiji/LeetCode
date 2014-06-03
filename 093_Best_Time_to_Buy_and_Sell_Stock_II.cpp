/*
 * Best Time to Buy and Sell Stock II
 * Total Accepted: 14347 Total Submissions: 39896
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        int buyIndex = -1;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                buyIndex = i;
                break;
            }
            if (i == prices.size() - 2)
                return 0;
        }

        int result = 0;
        while (true)
        {
            int sellIndex = getSellIndex(buyIndex, prices);

            result += (prices[sellIndex] - prices[buyIndex]);
            buyIndex = getBuyIndex(sellIndex, prices);

            if (buyIndex == -1)
                break;
        }
        return result;
    }

    int getBuyIndex(int sellIndex, const vector<int> &prices)
    {
        for (int i = sellIndex + 1; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                return i;
            }
        }

        return -1;
    }

    int getSellIndex(int buyIndex, const vector<int> &prices)
    {
        for (int i = buyIndex + 1; i < prices.size() - 1; i++)
        {
            if (prices[i] > prices[buyIndex] && prices[i + 1] < prices[i])
            {
                return i;
            }
        }

        return prices.size() - 1;
    }
};
