/*
 * Pascal's Triangle II
 * Total Accepted: 10276 Total Submissions: 34230
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        result.push_back(1);
        for (int i = 1; i <= rowIndex; i++)
        {
            result.insert(result.begin(), 1);
            for (int j = 1; j < i; j++)
            {
                result[j] = result[j] + result[j + 1];
            }
        }

        return result;
    }
};
