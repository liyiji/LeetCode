/*
 * Interleaving String
 * Total Accepted: 11177 Total Submissions: 59164
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        if (s1.empty())
            return (s2 == s3);
        if (s2.empty())
            return (s1 == s3);

        vector < vector<bool> > flags(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        flags[0][0] = true;
        for (int i = 0; i <= s1.size(); i++)
        {
            for (int j = 0; j <= s2.size(); j++)
            {
                if (i == 0 && j != 0)
                {
                    if (flags[i][j - 1] && s2[j - 1] == s3[j - 1])
                        flags[i][j] = true;
                }
                else if (j == 0 && i != 0)
                {
                    if (flags[i - 1][j] && s1[i - 1] == s3[i - 1])
                        flags[i][j] = true;
                }
                else if (i != 0 && j != 0)
                {
                    if ((flags[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (flags[i - 1][j] && s1[i - 1] == s3[i + j - 1]))
                    {
                        flags[i][j] = true;
                    }
                }
            }
        }

        return flags.back().back();
    }
};
