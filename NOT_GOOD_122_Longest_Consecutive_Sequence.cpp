/*
 * Longest Consecutive Sequence
 * Total Accepted: 13402 Total Submissions: 49022
 *
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */
class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        sort(num.begin(), num.end());

        size_t result = 1;
        size_t startIndex = 0;
        size_t subResult = 1;
        for (size_t i = 1; i < num.size(); i++)
        {
            if (num[i] == num[i - 1] + 1)
                subResult++;
            else
            {
                result = max(result, subResult);
                subResult = 1;
            }
        }
        return result;
    }
};
