/*
 * Rotate Image
 * Total Accepted: 10296 Total Submissions: 33430
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 */
class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j < n - 1 - i; j++)
            {
                int i1 = i;
                int i2 = j;
                int i3 = n - 1 - i;
                int i4 = n - 1 - j;
                int j1 = j;
                int j2 = n - 1 - i;
                int j3 = n - 1 - j;
                int j4 = i;
                singleRotate(i1, j1, i2, j2, i3, j3, i4, j4, matrix);
            }
        }
    }

    void singleRotate(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4, vector<vector<int> > &matrix)
    {
        swap(matrix[i1][j1], matrix[i2][j2]);
        swap(matrix[i1][j1], matrix[i4][j4]);
        swap(matrix[i3][j3], matrix[i4][j4]);
    }
};
