/*
 * Length of Last Word
 * Total Accepted: 11047 Total Submissions: 38782
 *
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 */
class Solution
{
public:
    int lengthOfLastWord(const char *s)
    {
        int iLastSpace = -1;
        int iStart = -1;
        int iEnd = -1;
        for (int i = 0;; i++)
        {
            if (s[i] == '\0')
                break;

            if (s[i] == ' ')
            {
                iLastSpace = i;
            }
            else
            {
                if (iStart <= iLastSpace)
                {
                    iStart = i; // iStart = iLastSpace + 1;
                    iEnd = iStart;
                }
                else
                {
                    iEnd = i;
                }
            }
        }

        if (iEnd < 0)
            return 0;

        return iEnd - iStart + 1;
    }
};
