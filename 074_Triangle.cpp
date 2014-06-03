/*
 * Triangle
 * Total Accepted: 10972 Total Submissions: 41192
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        vector<int> sum;

        for (int i = triangle.size() - 1; i >= 0; i--)
        {
            Min(triangle, i, sum);
        }
        return sum[0];
    }

    void Min(vector<vector<int> > &tri, int level, vector<int> &sum)
    {
        if (level == tri[tri.size() - 1].size() - 1)
        {
            for (int i = 0; i <= level; i++)
            {
                sum.push_back(tri[tri.size() - 1][i]);
            }
            return;
        }
        else
        {
            for (int i = 0; i < tri[level].size(); i++)
            {
                sum[i] = min(sum[i], sum[i + 1]) + tri[level][i];
            }
            sum.resize(level + 1);
        }
    }
};
