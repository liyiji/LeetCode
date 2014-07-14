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
    int numDistinct(string S, string T)
    {
        int lengthDiff = S.size() - T.size();
        if (lengthDiff < 0)
            return 0;
        if (lengthDiff == 0)
        {
            if (S == T)
                return 1;
            else
                return 0;
        }

        vector<size_t> lastIndices;
        int probe = T.size() - 1;
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == T[probe])
            {
                lastIndices.push_back(i);
                if (probe == 0)
                    break;
                probe--;
            }
        }
        if (probe)
            return 0;

        reverse(lastIndices.begin(), lastIndices.end());

        int result = getSub(S, 0, T, 0, lastIndices);
        return result;
    }

    int getSub(const string &S, size_t startS, const string &T, size_t startT, const vector<size_t> &lastIndices)
    {
        if (startT >= T.size())
            return 1;
        else
        {
            if (startS >= S.size())
                return 0;
            else
            {
                int result = 0;
                for (size_t i = startS; i <= lastIndices[startT]; i++)
                {
                    if (S[i] == T[startT])
                        result += getSub(S, i + 1, T, startT + 1, lastIndices);
                }
                return result;
            }
        }
    }
};
