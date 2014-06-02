/*
 * Search a 2D Matrix
 * Total Accepted: 11839 Total Submissions: 38761
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 *     Integers in each row are sorted from left to right.
 *     The first integer of each row is greater than the last integer of the previous row.
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * 
 * Given target = 3, return true.
 */
class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        if (target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[matrix.size() - 1].size() - 1])
            return false;

        int ith = 0;
        bool bFound = false;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][matrix[i].size() - 1])
            {
                ith = i;
                bFound = true;
                break;
            }
        }
        if (bFound == false)
            return false;

        int subSize = matrix[ith].size();
        for (int i = 0; i < subSize; i++)
        {
            if (matrix[ith][i] == target)
                return true;
            if (matrix[ith][i] > target)
                return false;
        }
    }
};
