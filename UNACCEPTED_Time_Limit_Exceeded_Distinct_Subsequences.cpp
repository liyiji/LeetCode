/*
 * Distinct Subsequences
 * Total Accepted: 10034 Total Submissions: 41295
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
        if (T.empty())
            return 1;
        if (S.size() < T.size())
            return 0;

        size_t dis = S.size() - T.size();
        int result = getSub(S, T, 0, 0, dis);
        return result;
    }

    int getSub(const string &s, const string &t, size_t sbegin, size_t tbegin, size_t dis)
    {
        if (sbegin >= s.size() || tbegin >= t.size() || tbegin > sbegin || s.size() - sbegin < t.size() - tbegin)
            return 0;
        if (dis == 0)
            return 1;

        int result = 0;
        if (s[sbegin] == t[tbegin])
        {
            result += getSub(s, t, sbegin + 1, tbegin + 1, dis - 1);
            sbegin++;
            while (sbegin < s.size() && s.size() - sbegin >= t.size() - tbegin)
            {
                if (s[sbegin] != t[tbegin])
                    sbegin++;
                else
                    break;
            }
            result += getSub(s, t, sbegin + 1, tbegin, dis);
        }
        else
        {
            sbegin++;
            while (sbegin < s.size() && s.size() - sbegin >= t.size() - tbegin)
            {
                if (s[sbegin] != t[tbegin])
                    sbegin++;
                else
                    break;
            }
            if (sbegin < s.size() && s.size() - sbegin >= t.size() - tbegin)
                result += getSub(s, t, sbegin, tbegin, dis);
        }
        return result;
    }
};
