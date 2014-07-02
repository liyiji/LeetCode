/*
 * Anagrams
 * Total Accepted: 10640 Total Submissions: 46101
 *
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */
bool lessThan(pair<string, string> a, pair<string, string> b)
{
    if (a.first < b.first)
        return true;
    return false;
}

class Solution
{
public:
    vector<string> anagrams(vector<string> &strs)
    {
        vector < string > result;
        if (strs.size() < 2)
            return result;

        vector < pair<string, string> > pairs;
        for (size_t i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            pairs.push_back(make_pair(tmp, strs[i]));
        }

        sort(pairs.begin(), pairs.end(), lessThan);

        size_t it = 0;
        while (it + 1 < pairs.size())
        {
            for (size_t add = 1; it + add < pairs.size(); add++)
            {
                if (pairs[it + add].first != pairs[it].first)
                {
                    if (add > 1)
                    {
                        for (size_t add2 = 0; add2 < add; add2++)
                        {
                            result.push_back(pairs[it + add2].second);
                        }
                    }
                    it += add;
                    break;
                }
                if (it + add + 1 == pairs.size())
                {
                    if (add)
                    {
                        for (size_t add2 = 0; add2 <= add; add2++)
                        {
                            result.push_back(pairs[it + add2].second);
                        }
                        it += (add + 1);
                        break;
                    }
                }
            }
        }

        return result;
    }
};
