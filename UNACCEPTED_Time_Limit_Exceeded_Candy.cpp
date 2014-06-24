/*
 * Candy
 * Total Accepted: 12143 Total Submissions: 67045
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
        for (size_t i = 0; i < ratings.size(); i++)
        {
            if (i == 0)
            {
                result[i] = 1;
            }
            else
            {
                if (ratings[i] > ratings[i - 1])
                {
                    result[i] = result[i - 1] + 1;
                }
                else if (ratings[i] < ratings[i - 1])
                {
                    if (result[i - 1] > 1)
                        result[i] = 1;
                    else // result[i - 1] == 1
                    {
                        size_t end = i - 1;
                        size_t start = end;
                        while (start >= 0)
                        {
                            if (rating[start - 1] > rating[start] && result[start - 1] - result[start] == 1)
                                start--;
                            else
                                break;
                        }

                        for (size_t it = start; it <= end; it++)
                        {
                            result[it]++;
                        }
                        result[i] = 1;
                    }
                }
                else // (ratings[i] == ratings[i - 1])
                {
                    result[i] = 1;
                }
            }
        }

        return accumulate(result.begin(), result.end(), 0);
    }
};
