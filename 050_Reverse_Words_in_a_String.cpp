/*
 * Reverse Words in a String
 * Total Accepted: 15197 Total Submissions: 109666
 *
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * click to show clarification.
 * Clarification:
 *
 *     What constitutes a word?
 *     A sequence of non-space characters constitutes a word.
 *     Could the input string contain leading or trailing spaces?
 *     Yes. However, your reversed string should not contain leading or trailing spaces.
 *     How about multiple spaces between two words?
 *     Reduce them to a single space in the reversed string.
 *
 */
class Solution
{
public:
    void reverseWords(string &s)
    {
        int head = 0;
        int tail = -1;

        // calculate space length in the head
        for (int i = 0; i < s.size(); i++)
        {
            head = i;
            if (s[i] != ' ')
            {
                head = i;
                break;
            }
        }
        // calculate space length in the tail
        for (int i = s.size() - 1; i >= 0; i--)
        {
            tail = i;
            if (s[i] != ' ')
            {
                tail = i;
                break;
            }
        }

        // reverse all the string and shrink
        reverse(s.begin(), s.begin() + tail + 1);
        s.resize(max((tail - head + 1), 0));

        int subStart = -1;
        int subEnd = -1;
        int nextStart = 0;
        while (true)
        {
            if (nextStart >= s.size())
                break;

            subStart = nextStart;
            while (subStart < s.size() && s[subStart] == ' ')
            {
                subStart++;
            }

            if (subStart >= s.size())
                break;

            for (int i = subStart; i < s.size(); i++)
            {
                if (s[i] == ' ')
                {
                    subEnd = i - 1;
                    break;
                }
                if (i == s.size() - 1)
                {
                    subEnd = s.size() - 1;
                }
            }

            reverse(s.begin() + nextStart, s.begin() + nextStart + subEnd - nextStart + 1);
            nextStart = subEnd - (subStart - nextStart - 2);
        }
        s.resize(max((nextStart - 1), 0));
    }
};
