/*
 * Word Break II
 * Total Accepted: 11438 Total Submissions: 71991
 *
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */
class Solution
{
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        vector < string > result;

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
                return result;
        }

        vector < vector<string> > preResult = processSub(s, dict);
        result.resize(preResult.size());
        for (int i = 0; i < preResult.size(); i++)
        {
            for (int j = 0; j < preResult[i].size(); j++)
            {
                result[i].append(preResult[i][j]);
                if (j + 1 != preResult[i].size())
                    result[i].append(" ");
            }
        }
        return result;
    }

    vector<vector<string> > processSub(string s, const unordered_set<string> &dict)
    {
        vector < vector<string> > result;
        for (int length = 1; length <= s.size(); length++)
        {
            string left = s.substr(0, length);
            if (dict.find(left) != dict.end())
            {
                if (length < s.size())
                {
                    vector < vector<string> > subResult = processSub(s.substr(length, s.size() - length), dict);
                    if (subResult.size())
                    {
                        for (int i = 0; i < subResult.size(); i++)
                        {
                            subResult[i].insert(subResult[i].begin(), left);
                        }
                        for (int i = 0; i < subResult.size(); i++)
                        {
                            result.push_back(subResult[i]);
                        }
                    }
                }
                else
                {
                    vector < string > subResult(1, left);
                    result.push_back(subResult);
                }
            }
        }

        return result;
    }
};
