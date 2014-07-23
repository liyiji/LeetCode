/*
 * Edit Distance
 * Total Accepted: 11265 Total Submissions: 45022
 *
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
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
