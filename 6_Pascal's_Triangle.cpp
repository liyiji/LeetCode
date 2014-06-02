/*
 * Pascal's Triangle
 * Total Accepted: 11976 Total Submissions: 37712
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 */
class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector <vector<int> > result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> tmp;
            if (i == 0)
            {
                tmp.push_back(1);
            }
            else if (i == 1)
            {
                tmp.push_back(1);
                tmp.push_back(1);
            }
            else
            {
                tmp.push_back(1);
                for (int j = 0; j < result[i - 1].size() - 1; j++)
                    tmp.push_back(result[i - 1][j] + result[i - 1][j + 1]);

                tmp.push_back(1);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
