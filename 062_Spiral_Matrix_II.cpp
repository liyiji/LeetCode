/*
 * Spiral Matrix II
 * Total Accepted: 8433 Total Submissions: 27824
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 * You should return the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 */
class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > result(n);
        for (int i = 0; i < n; i++)
        {
            result[i].resize(n);
        }

        int mBeg = 0;
        int nBeg = 0;
        int mEnd = n - 1;
        int nEnd = n - 1;

        int num = 1;
        while (true)
        {
            for (int i = nBeg; i <= nEnd; i++)
            {
                result[mBeg][i] = num;
                num++;
            }
            mBeg++;
            if (num > n * n)
                break;

            for (int i = mBeg; i <= mEnd; i++)
            {
                result[i][nEnd] = num;
                num++;
            }
            nEnd--;
            if (num > n * n)
                break;

            for (int i = nEnd; i >= nBeg; i--)
            {
                result[mEnd][i] = num;
                num++;
            }
            mEnd--;
            if (num > n * n)
                break;

            for (int i = mEnd; i >= mBeg; i--)
            {
                result[i][nBeg] = num;
                num++;
            }
            nBeg++;
            if (num > n * n)
                break;
        }

        return result;
    }
};
