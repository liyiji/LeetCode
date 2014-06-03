/*
 * Minimum Path Sum
 * Total Accepted: 10511 Total Submissions: 34411
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */
class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        int result = grid[0][0];
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                else if (j == 0)
                    grid[i][j] = grid[i][j] + grid[i - 1][j];
                else if (i != 0 && j != 0)
                    grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];

                if (i == grid.size() - 1 && j == grid[i].size() - 1)
                    result = grid[i][j];
            }
        }
        return result;
    }
};
