/*
 * Best Time to Buy and Sell Stock III
 * Total Accepted: 9960 Total Submissions: 45322
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyIndex = -1;
        int sellIndex = -1;

        int oneMax = getSub(prices, 0, prices.size() - 1, buyIndex, sellIndex);

        if (oneMax == 0)
            return oneMax;

        int noUse1, noUse2;
        int leftMax = getSub(prices, 0, buyIndex - 1, noUse1, noUse2);
        int rightMax = getSub(prices, sellIndex + 1, prices.size() - 1, noUse1, noUse2);

        vector<int> reversedPrices;
        for (size_t i = sellIndex - 1; i > buyIndex; i--)
        {
            reversedPrices.push_back(prices[i]);
        }
        int midMax = getSub(reversedPrices, 0, reversedPrices.size() - 1, noUse1, noUse2);

        return max(max(leftMax, rightMax), midMax) + oneMax;
    }

    int getSub(const vector<int> &prices, int startIndex, int endIndex, int &buyIndex, int &sellIndex)
    {
        if (startIndex >= endIndex)
        {
            buyIndex = -1;
            sellIndex = -1;
            return 0;
        }

        if (endIndex - startIndex == 1)
        {
            if (prices[endIndex] > prices[startIndex])
            {
                buyIndex = startIndex;
                sellIndex = endIndex;
                return prices[endIndex] - prices[startIndex];
            }

            buyIndex = -1;
            sellIndex = -1;
            return 0;
        }

        int midIndex = (startIndex + endIndex + 1) / 2;

        int leftBuyIndex = -1;
        int leftSellIndex = -1;
        int rightBuyIndex = -1;
        int rightSellIndex = -1;
        int profitSubLeft = getSub(prices, startIndex, midIndex - 1, leftBuyIndex, leftSellIndex);
        int profitSubRight = getSub(prices, midIndex, endIndex, rightBuyIndex, rightSellIndex);
        int profitSub = max(profitSubLeft, profitSubRight);

        int leftMinIndex = findIndexOfMin(prices, startIndex, midIndex - 1);
        int rightMaxIndex = findIndexOfMax(prices, midIndex, endIndex);
        int profitSplit = prices[rightMaxIndex] - prices[leftMinIndex];

        if (max(profitSub, profitSplit) == 0)
        {
            buyIndex = -1;
            sellIndex = -1;
            return 0;
        }

        if (profitSplit >= profitSub)
        {
            buyIndex = leftMinIndex;
            sellIndex = rightMaxIndex;
            return profitSplit;
        }
        else
        {
            if (profitSubLeft >= profitSubRight)
            {
                buyIndex = leftBuyIndex;
                sellIndex = leftSellIndex;
            }
            else
            {
                buyIndex = rightBuyIndex;
                sellIndex = rightSellIndex;
            }
            return profitSub;
        }
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
