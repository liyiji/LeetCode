/*
 * Longest Common Prefix
 * Total Accepted: 11138 Total Submissions: 41305
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int minLength = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            if (i == 0)
            {
                minLength = strs[0].size();
            }
            else if (strs[i].size() < minLength)
            {
                minLength = strs[i].size();
            }
        }

        string pre;
        for (int i = 0; i < minLength; i++)
        {
            char a = strs[0][i];
            bool b = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != a)
                {
                    b = false;
                    break;
                }
            }

            if (b)
            {
                pre.push_back(a);
            }
            else
            {
                break;
            }
        }

        return pre;
    }
};
