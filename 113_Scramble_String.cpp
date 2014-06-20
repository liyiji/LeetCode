/*
 * Scramble String
 * Total Accepted: 8289 Total Submissions: 37633
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 *
 * Below is one possible representation of s1 = "great":
 *
 *     great
 *    /    \
 *   gr    eat
 *  / \    /  \
 * g   r  e   at
 *            / \
 *           a   t
 *
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 *
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 *
 *     rgeat
 *    /    \
 *   rg    eat
 *  / \    /  \
 * r   g  e   at
 *            / \
 *           a   t
 *
 * We say that "rgeat" is a scrambled string of "great".
 *
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 *
 *     rgtae
 *    /    \
 *   rg    tae
 *  / \    /  \
 * r   g  ta  e
 *        / \
 *       t   a
 *
 * We say that "rgtae" is a scrambled string of "great".
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.empty() || s2.empty())
            return false;
        if (s1.size() != s2.size())
            return false;
        if (s1.find_first_not_of(s2) != string::npos)
            return false;
        if (s2.find_first_not_of(s1) != string::npos)
            return false;
        if (s1 == s2)
            return true;

        string::size_type length = s1.size();

        if (length == 0)
            return false;

        for (size_t leftLength = 1; leftLength < length; leftLength++)
        {
            size_t rightLength = length - leftLength;

            string l1 = s1.substr(0, leftLength);
            string l2 = s2.substr(0, leftLength);
            string r1 = s1.substr(leftLength, rightLength);
            string r2 = s2.substr(leftLength, rightLength);

            if (l1.find_first_not_of(r2) == string::npos && l2.find_first_not_of(r1) == string::npos && r1.find_first_not_of(l2) == string::npos && r2.find_first_not_of(l1) == string::npos)
            {
                if (isScramble(l1, r2) && isScramble(r1, l2))
                {
                    return true;
                }
            }
            if (l1.find_first_not_of(l2) == string::npos && l2.find_first_not_of(l1) == string::npos && r1.find_first_not_of(r2) == string::npos && r2.find_first_not_of(r1) == string::npos)
            {
                if (isScramble(l1, l2) && isScramble(r1, r2))
                {
                    return true;
                }
            }

            l1 = s1.substr(0, leftLength);
            l2 = s2.substr(0, rightLength);
            r1 = s1.substr(leftLength, rightLength);
            r2 = s2.substr(rightLength, leftLength);
            if (l1.find_first_not_of(r2) == string::npos && l2.find_first_not_of(r1) == string::npos && r1.find_first_not_of(l2) == string::npos && r2.find_first_not_of(l1) == string::npos)
            {
                if (isScramble(l1, r2) && isScramble(r1, l2))
                {
                    return true;
                }
            }
            if (l1.find_first_not_of(l2) == string::npos && l2.find_first_not_of(l1) == string::npos && r1.find_first_not_of(r2) == string::npos && r2.find_first_not_of(r1) == string::npos)
            {
                if (isScramble(l1, l2) && isScramble(r1, r2))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
