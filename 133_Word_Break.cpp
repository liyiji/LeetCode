/*
 * Word Break
 * Total Accepted: 17068 Total Submissions: 83272
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
        for (size_t i = 0; i < s.size(); i++)
        {
            string singleChar = s.substr(i, 1);
            bool bFound = false;

            unordered_set<string>::iterator it;
            for (it = dict.begin(); it != dict.end(); it++)
            {
                string str = *it;

                for (size_t j = 0; j < str.size(); j++)
                {
                    if (str[j] == singleChar[0])
                    {
                        bFound = true;
                        break;
                    }
                }
                if (bFound)
                    break;
            }

            if (bFound == false)
                return false;
        }

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
