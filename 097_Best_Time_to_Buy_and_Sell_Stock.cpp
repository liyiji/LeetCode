/*
 * Best Time to Buy and Sell Stock
 * Total Accepted: 14535 Total Submissions: 47193
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return tmp(prices, 0, prices.size() - 1);
    }

    int tmp(const vector<int> &prices, int startIndex, int endIndex)
    {
        if (startIndex >= endIndex)
            return 0;

        if (endIndex - startIndex == 1)
            return max(0, prices[endIndex] - prices[startIndex]);

        int midIndex = (startIndex + endIndex + 1) / 2;
        int profitSub = max(tmp(prices, startIndex, midIndex - 1), tmp(prices, midIndex, endIndex));
        int profitSplit = max(0, prices[findIndexOfMax(prices, midIndex, endIndex)] - prices[findIndexOfMin(prices, startIndex, midIndex - 1)]);

        return max(profitSub, profitSplit);
    }

    int findIndexOfMin(const vector<int> &vec, int startIndex, int endIndex)
    {
        int index = startIndex;
        for (int i = startIndex + 1; i <= endIndex; i++)
        {
            if (vec[i] <= vec[index])
                index = i;
        }
        return index;
    }

    int findIndexOfMax(const vector<int> &vec, int startIndex, int endIndex)
    {
        int index = startIndex;
        for (int i = startIndex + 1; i <= endIndex; i++)
        {
            if (vec[i] >= vec[index])
                index = i;
        }
        return index;
    }
};
