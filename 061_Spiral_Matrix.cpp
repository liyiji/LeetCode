/*
 * Spiral Matrix
 * Total Accepted: 8352 Total Submissions: 41069
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 *
 * You should return [1,2,3,6,9,8,7,4,5].
 */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        int m = matrix.size();
        int n;
        if (m)
        {
            n = matrix[0].size();
        }

        vector<int> result;
        if (m * n == 0)
        {
            return result;
        }

        int mBeg = 0;
        int nBeg = 0;
        int mEnd = m - 1;
        int nEnd = n - 1;

        while (true)
        {
            for (int i = nBeg; i <= nEnd; i++)
            {
                result.push_back(matrix[mBeg][i]);
            }
            mBeg++;
            if (result.size() == m * n)
                break;

            for (int i = mBeg; i <= mEnd; i++)
            {
                result.push_back(matrix[i][nEnd]);
            }
            nEnd--;
            if (result.size() == m * n)
                break;

            for (int i = nEnd; i >= nBeg; i--)
            {
                result.push_back(matrix[mEnd][i]);
            }
            mEnd--;
            if (result.size() == m * n)
                break;

            for (int i = mEnd; i >= mBeg; i--)
            {
                {
                    result.push_back(matrix[i][nBeg]);
                }
            }
            nBeg++;
            if (result.size() == m * n)
                break;
        }

        return result;
    }
};
