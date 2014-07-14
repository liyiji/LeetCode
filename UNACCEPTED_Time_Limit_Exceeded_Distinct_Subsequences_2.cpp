/*
 * Distinct Subsequences
 * Total Accepted: 11012 Total Submissions: 45290
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
    int minDistance(string word1, string word2)
    {
        if (word1.empty())
            return word2.size();
        if (word2.empty())
            return word1.size();

        size_t l1 = word1.size();
        size_t l2 = word2.size();
        vector < vector<size_t> > matrix(l1 + 1, vector < size_t > (l2 + 1, 0));
        for (size_t i = 0; i <= l1; ++i)
        {
            matrix[i][0] = i;
        }
        for (size_t i = 0; i <= l2; ++i)
        {
            matrix[0][i] = i;
        }

        for (size_t i = 1; i <= l1; ++i)
        {
            for (size_t j = 1; j <= l2; ++j)
            {
                matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1));
            }
        }

        return matrix[l1][l2];
    }
};
