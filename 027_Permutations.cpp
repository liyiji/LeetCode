/*
 * Permutations
 * Total Accepted: 14722 Total Submissions: 47868
 *
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
class Solution
{
public:
    vector<vector<int> > permute(vector<int> &num)
    {
        vector<vector<int> > result;
        int n = num.size();
        result.resize(pCount(n));
        for (int i = 0; i < result.size(); i++)
        {
            result[i].resize(n);
        }

        fillSubMatrix(result, 0, 0, num);
        return result;
    }

    void fillSubMatrix(vector<vector<int> > &result, int line, int pos, vector<int> in)
    {
        int n = in.size();
        if (n == 1)
        {
            result[line][pos] = in[0];
            return;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int startLine = line + i * pCount(n - 1);
                vector<int> subIn(n - 1);
                for (int j = 0; j < n - 1; j++)
                {
                    if (j < i)
                    {
                        subIn[j] = in[j];
                    }
                    else if (j >= i)
                    {
                        subIn[j] = in[j + 1];
                    }
                }

                for (int j = 0; j < pCount(n - 1); j++)
                {
                    result[j + startLine][pos] = in[i];
                }
                fillSubMatrix(result, startLine, pos + 1, subIn);
            }
        }
    }

    int pCount(int n)
    {
        int sum = 1;
        for (int i = 1; i <= n; i++)
        {
            sum *= i;
        }
        return sum;
    }
};
