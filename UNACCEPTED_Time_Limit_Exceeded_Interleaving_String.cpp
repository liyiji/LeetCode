/*
 * Interleaving String
 * Total Accepted: 9515 Total Submissions: 50873
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
        if (s1.empty() || s2.empty())
            return true;

        size_t c1 = 0;
        size_t c2 = 0;
        size_t c3 = 0;
        stack<int> vec;
        while (c1 <= s1.size() && c2 <= s2.size() && c3 <= s3.size())
        {
            if (c1 == s1.size())
            {
                for (int i = 0; i + c3 < s3.size(); i++)
                {
                    if (s2[c2 + i] != s3[c3 + i])
                        return false;
                }
                return true;
            }

            if (c2 == s2.size())
            {
                for (int i = 0; i + c3 < s3.size(); i++)
                {
                    if (s1[c1 + i] != s3[c3 + i])
                        return false;
                }
                return true;
            }

            if (s1[c1] != s3[c3] && s2[c2] != s3[c3])
            {
                if (vec.empty())
                {
                    return false;
                }
                else
                {
                    c2 = vec.top() + 1;
                    vec.pop();
                    c1 = vec.top();
                    vec.pop();
                    c3 = c1 + c2;
                }
            }
            else
            {
                if (s1[c1] == s3[c3] && s2[c2] == s3[c3])
                {
                    vec.push(c1);
                    vec.push(c2);
                    c1++;
                    c3++;
                }
                else
                {
                    if (s1[c1] == s3[c3])
                    {
                        c1++;
                        c3++;
                    }
                    else if (s2[c2] == s3[c3])
                    {
                        c2++;
                        c3++;
                    }
                }
            }
        }

        return true;
    }
};
