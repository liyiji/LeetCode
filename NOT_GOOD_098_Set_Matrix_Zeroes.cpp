/*
 * Set Matrix Zeroes
 * Total Accepted: 10523 Total Submissions: 34823
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 * click to show follow up.
 * Follow up:
 *
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 */
class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return;

        int n = matrix[0].size();
        if (n == 0)
            return;

        vector<bool> vec(m, false);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    vec[i] = true;
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < m; k++)
                    {
                        matrix[k][j] = 0;
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (vec[i])
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
