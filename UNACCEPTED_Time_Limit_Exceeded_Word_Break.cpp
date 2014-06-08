/*
 * Word Break
 * Total Accepted: 14268 Total Submissions: 70262
 *
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */
class Solution
{
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        return processSub(s, dict);
    }

    bool processSub(string s, const unordered_set<string> &dict)
    {
        for (int length = 1; length <= s.size(); length++)
        {
            string left = s.substr(0, length);
            if (dict.find(left) != dict.end())
            {
                if (length < s.size())
                {
                    if (processSub(s.substr(length, s.size() - length), dict))
                        return true;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};
