/*
 * Anagrams
 * Total Accepted: 10640 Total Submissions: 46101
 *
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */
bool shorterThan(pair<string, string> a, pair<string, string> b)
{
    if (a.first.size() < b.first.size())
        return true;
    if (a.first.size() > b.first.size())
        return false;
    for (size_t i = 0; i < a.first.size(); i++)
    {
        if (a.first[i] < b.first[i])
            return true;
        else if (a.first[i] > b.first[i])
            return false;
        else
            continue;
    }
    return true;
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

        sort(pairs.begin(), pairs.end(), shorterThan);

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
