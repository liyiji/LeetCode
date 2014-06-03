/*
 * Longest Substring Without Repeating Characters
 * Total Accepted: 14301 Total Submissions: 64587
 *
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int curMax = 0;
        int start, end, cursor;
        start = end = cursor = 0;

        while (true)
        {
            if (start >= s.size() - curMax)
                break;
            if (curMax == 0)
                curMax = 1;
            if (end == start)
                end++;
            if (end >= s.size())
                break;

            if (s[cursor] != s[end])
            {
                if (cursor != end - 1)
                {
                    cursor++;
                }
                else
                {
                    end++;
                    cursor = start;
                    curMax = max(end - cursor, curMax);
                    if (start >= s.size() - curMax || end >= s.size())
                        break;
                }
            }
            else
            {
                curMax = max(end - cursor, curMax);
                start = cursor + 1;
                cursor = start;
                end++;
                if (start >= s.size() - curMax || end >= s.size())
                    break;
            }
        }

        return curMax;
    }
};
