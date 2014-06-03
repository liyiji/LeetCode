/*
 * Two Sum
 * Total Accepted: 20879 Total Submissions: 113696
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> smallOddIndices;
        vector<int> largeOddIndices;
        vector<int> smallEvenIndices;
        vector<int> largeEvenIndices;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] <= target / 2)
            {
                if (numbers[i] % 2)
                    smallOddIndices.push_back(i);
                else
                    smallEvenIndices.push_back(i);
            }
            if (numbers[i] >= target / 2)
            {
                if (numbers[i] % 2)
                    largeOddIndices.push_back(i);
                else
                    largeEvenIndices.push_back(i);
            }
        }

        vector<int> result;

        if (target % 2)
        {
            for (int i = 0; i < smallOddIndices.size(); i++)
            {
                for (int j = 0; j < largeEvenIndices.size(); j++)
                {
                    if (numbers[smallOddIndices[i]] + numbers[largeEvenIndices[j]] == target)
                    {
                        if (smallOddIndices[i] != largeEvenIndices[j])
                        {
                            result.push_back(min(smallOddIndices[i] + 1, largeEvenIndices[j] + 1));
                            result.push_back(max(smallOddIndices[i] + 1, largeEvenIndices[j] + 1));
                            return result;
                        }
                    }
                }
            }

            for (int i = 0; i < smallEvenIndices.size(); i++)
            {
                for (int j = 0; j < largeOddIndices.size(); j++)
                {
                    if (numbers[smallEvenIndices[i]] + numbers[largeOddIndices[j]] == target)
                    {
                        if (smallEvenIndices[i] != largeOddIndices[j])
                        {
                            result.push_back(min(smallEvenIndices[i] + 1, largeOddIndices[j] + 1));
                            result.push_back(max(smallEvenIndices[i] + 1, largeOddIndices[j] + 1));
                            return result;
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < smallOddIndices.size(); i++)
            {
                for (int j = 0; j < largeOddIndices.size(); j++)
                {
                    if (numbers[smallOddIndices[i]] + numbers[largeOddIndices[j]] == target)
                    {
                        if (smallOddIndices[i] != largeOddIndices[j])
                        {
                            result.push_back(min(smallOddIndices[i] + 1, largeOddIndices[j] + 1));
                            result.push_back(max(smallOddIndices[i] + 1, largeOddIndices[j] + 1));
                            return result;
                        }
                    }
                }
            }

            for (int i = 0; i < smallEvenIndices.size(); i++)
            {
                for (int j = 0; j < largeEvenIndices.size(); j++)
                {
                    if (numbers[smallEvenIndices[i]] + numbers[largeEvenIndices[j]] == target)
                    {
                        if (smallEvenIndices[i] != largeEvenIndices[j])
                        {
                            result.push_back(min(smallEvenIndices[i] + 1, largeEvenIndices[j] + 1));
                            result.push_back(max(smallEvenIndices[i] + 1, largeEvenIndices[j] + 1));
                            return result;
                        }
                    }
                }
            }
        }

        return result;
    }
};
