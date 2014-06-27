/*
 * Maximal Rectangle
 * Total Accepted: 7499 Total Submissions: 34729
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */
class Solution
{
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        int result = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            if ((matrix.size() - i) * matrix[0].size() <= result)
                break;
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '0')
                    continue;

                if ((matrix.size() - i) * (matrix[0].size() - j) <= result)
                    break;

                size_t right = j;
                while (right < matrix[0].size())
                {
                    if (matrix[i][right] == '0')
                    {
                        break;
                    }
                    right++;
                }
                right--;

                if (right - j + 1 > result)
                {
                    result = right - j + 1;
                }
                else if ((right - j + 1) * (matrix.size() - i) <= result)
                    continue;

                size_t down = i;
                while (down < matrix.size())
                {
                    if (down > i)
                    {
                        if (matrix[down][j] == '0')
                            break;

                        size_t tmpRight = j + 1;
                        while (tmpRight <= right)
                        {
                            if (matrix[down][tmpRight] == '0')
                            {
                                right = tmpRight - 1;
                                break;
                            }
                            tmpRight++;
                        }

                        int subResult = (down - i + 1) * (right - j + 1);
                        if (subResult > result)
                        {
                            result = subResult;
                        }
                        if ((right - j + 1) * (matrix.size() - i) <= result)
                            break;
                    }
                    down++;
                }
            }
        }

        return result;
    }
};
