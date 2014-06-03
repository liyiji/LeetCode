/*
 * Unique Paths
 * Total Accepted: 11857 Total Submissions: 38684
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 */
class Solution
{
public:
    // Time Limit Exceeded if use recursion
    int uniquePaths(int m, int n)
    {
        vector<vector<int> > tmp(m);
        for (int i = 0; i < tmp.size(); i++)
        {
            tmp[i].resize(n);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    tmp[i][j] = 1;
                }
                else
                {
                    tmp[i][j] = tmp[i][j - 1] + tmp[i - 1][j];
                }
            }
        }

        return tmp[m - 1][n - 1];
    }
};
