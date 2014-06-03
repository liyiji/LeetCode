/*
 * Unique Paths II
 * Total Accepted: 8875 Total Submissions: 32484
 *
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 *
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 *
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 */
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;

        vector<vector<int> > tmp(m);
        for (int i = 0; i < tmp.size(); i++)
        {
            tmp[i].resize(n);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    if (i == 0 && j == 0)
                        tmp[i][j] = 1;
                    else if (i == 0 && j != 0)
                        tmp[i][j] = tmp[i][j - 1];
                    else if (j == 0 && i != 0)
                        tmp[i][j] = tmp[i - 1][j];
                    else
                        tmp[i][j] = tmp[i][j - 1] + tmp[i - 1][j];
                }
                else
                {
                    tmp[i][j] = 0;
                }
            }
        }

        return tmp[m - 1][n - 1];
    }
};
