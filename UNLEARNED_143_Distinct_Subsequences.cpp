/*
 * Distinct Subsequences
 * Total Accepted: 11611 Total Submissions: 47567
 *
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 */
class Solution
{
public:
    int numDistinct(string S, string T)
    {
        if (S.empty())
            return 0;
        if (T.empty())
            return 1;
        if (S.size() < T.size())
            return 0;
        if (S.size() == T.size())
        {
            if (S == T)
                return 1;
            else
                return 0;
        }

        vector < vector<int> > matrix(T.size(), vector<int>(S.size(), 0));
        if (T[0] == S[0])
            matrix[0][0] = 1;
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == T[0])
                matrix[0][i] = matrix[0][i - 1] + 1;
            else
                matrix[0][i] = matrix[0][i - 1];
        }

        for (int i = 1; i < T.size(); i++)
        {
            for (int j = i; j < S.size(); j++)
            {
                if (T[i] == S[j])
                    matrix[i][j] = matrix[i - 1][j - 1] + matrix[i][j - 1];
                else
                    matrix[i][j] = matrix[i][j - 1];
            }
        }

        return matrix.back().back();
    }
};
