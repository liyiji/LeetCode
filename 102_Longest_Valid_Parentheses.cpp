/*
 * Longest Valid Parentheses
 * Total Accepted: 9446 Total Submissions: 49902
 *
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int result = 0;
        for (size_t i = 0; i + result + 1 < s.size();)
        {
            if (s[i] != '(')
            {
                i++;
                continue;
            }

            int lCount = 1;
            int rCount = 0;
            int distance = lCount - rCount;
            int lastMatchIndex = -1;
            bool bChangeI = false;
            bool bIncreaseDistance = true;
            for (size_t j = i + 1; j < s.size(); j++)
            {
                if (s[j] == '(')
                {
                    lCount++;
                }
                else
                {
                    bIncreaseDistance = false;
                    rCount++;
                }

                if (rCount == lCount)
                {
                    lastMatchIndex = j;
                    i = lastMatchIndex + 1;
                    result = max(result, rCount + lCount);
                    bChangeI = true;
                }
                else if (rCount > lCount)
                {
                    i = j + 1;
                    bChangeI = true;
                    break;
                }

                if (bIncreaseDistance)
                {
                    distance = max(distance, lCount - rCount);
                }
                else
                {
                    distance = min(distance, lCount - rCount);
                }

                if (j + 1 == s.size())
                {
                    if (bChangeI)
                    {
                        break;
                    }
                    else
                    {
                        if (distance > 0)
                        {
                            i += distance;
                            bChangeI = true;
                        }
                    }
                }
            }

            if (bChangeI == false)
                i++;
        }

        return result;
    }
};
