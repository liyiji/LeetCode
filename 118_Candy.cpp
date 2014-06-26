/*
 * Candy
 * Total Accepted: 12288 Total Submissions: 67760
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 *     Each child must have at least one candy.
 *     Children with a higher rating get more candies than their neighbors.
 *
 * What is the minimum candies you must give?
 */
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> result(ratings.size(), 0);
        size_t startIndex, endIndex;
        startIndex = 0;
        endIndex = 0;
        vector<size_t> subMinIndices, subMaxIndices;

        for (size_t i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] < ratings[i - 1])
            {
                if (i + 1 == ratings.size() || ratings[i + 1] >= ratings[i])
                {
                    subMinIndices.push_back(i);
                    if (subMinIndices[0] != startIndex && subMaxIndices.empty())
                        subMaxIndices.push_back(startIndex);
                }
            }
            else if (ratings[i] > ratings[i - 1])
            {
                if (i + 1 == ratings.size() || ratings[i + 1] <= ratings[i])
                {
                    subMaxIndices.push_back(i);
                    if (subMaxIndices[0] != startIndex && subMinIndices.empty())
                        subMinIndices.push_back(startIndex);
                }
            }
            else //if (ratings[i] == ratings[i - 1])
            {
                endIndex = i - 1;
                getSub(ratings, result, startIndex, endIndex, subMinIndices, subMaxIndices);
                startIndex = i;
                endIndex = 0;
                subMinIndices.clear();
                subMaxIndices.clear();
            }
        }

        getSub(ratings, result, startIndex, ratings.size() - 1, subMinIndices, subMaxIndices);

        return accumulate(result.begin(), result.end(), 0);
    }

    void getSub(const vector<int> &ratings, vector<int> &result, size_t startIndex, size_t endIndex, vector<size_t> subMinIndices, vector<size_t> subMaxIndices)
    {
        if (startIndex == endIndex) // (subMinIndices.empty() && subMaxIndices.empty())
        {
            result[startIndex] = 1;
            return;
        }

        if (subMinIndices.size() == 1 && subMaxIndices.size() == 1)
        {
            if (subMinIndices[0] < subMaxIndices[0])
            {
                for (size_t i = subMinIndices[0]; i <= subMaxIndices[0]; i++)
                {
                    result[i] = i - subMinIndices[0] + 1;
                }
            }
            else if (subMinIndices[0] > subMaxIndices[0])
            {
                for (size_t i = subMaxIndices[0]; i <= subMinIndices[0]; i++)
                {
                    result[i] = subMinIndices[0] - i + 1;
                }
            }
            return;
        }

        if (subMinIndices.size() == 1)
        {
            if (subMaxIndices.size() != 2)
                return;

            for (size_t i = subMaxIndices[0]; i <= subMinIndices[0]; i++)
            {
                result[i] = subMinIndices[0] - i + 1;
            }
            for (size_t i = subMinIndices[0]; i <= subMaxIndices[1]; i++)
            {
                result[i] = i - subMinIndices[0] + 1;
            }
            return;
        }

        if (subMaxIndices.size() == 1)
        {
            if (subMinIndices.size() != 2)
                return;

            for (size_t i = subMinIndices[0]; i < subMaxIndices[0]; i++)
            {
                result[i] = i - subMinIndices[0] + 1;
            }
            for (size_t i = subMaxIndices[0] + 1; i <= subMinIndices[1]; i++)
            {
                result[i] = subMinIndices[1] - i + 1;
            }
            result[subMaxIndices[0]] = max(result[subMaxIndices[0] - 1], result[subMaxIndices[0] + 1]) + 1;
            return;
        }

        size_t subMinIndexIndex = 0;
        size_t subMaxIndexIndex = 0;
        while (subMinIndexIndex < subMinIndices.size() && subMaxIndexIndex < subMaxIndices.size())
        {
            if (subMinIndices[subMinIndexIndex] < subMaxIndices[subMaxIndexIndex])
            {
                for (size_t i = subMinIndices[subMinIndexIndex]; i < subMaxIndices[subMaxIndexIndex]; i++)
                {
                    result[i] = i - subMinIndices[subMinIndexIndex] + 1;
                }
                subMinIndexIndex++;
            }
            else if (subMinIndices[subMinIndexIndex] > subMaxIndices[subMaxIndexIndex])
            {
                for (size_t i = subMaxIndices[subMaxIndexIndex] + 1; i <= subMinIndices[subMinIndexIndex]; i++)
                {
                    result[i] = subMinIndices[subMinIndexIndex] - i + 1;
                }
                subMaxIndexIndex++;
            }
            else
            {
                // Never reach here
                return;
            }
        }

        for (size_t i = 0; i < subMaxIndices.size(); i++)
        {
            if (subMaxIndices[i] == startIndex)
                result[subMaxIndices[i]] = result[subMaxIndices[i] + 1] + 1;
            else if (subMaxIndices[i] == endIndex)
                result[subMaxIndices[i]] = result[subMaxIndices[i] - 1] + 1;
            else
                result[subMaxIndices[i]] = max(result[subMaxIndices[i] - 1], result[subMaxIndices[i] + 1]) + 1;
        }
    }
};
