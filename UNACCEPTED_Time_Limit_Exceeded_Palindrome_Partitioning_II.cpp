/*
 * Palindrome Partitioning II
 * Total Accepted: 9321 Total Submissions: 53010
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
class Solution
{
public:
    int minCut(string s)
    {
        int result = s.size() - 1;
        vector < vector<string> > vec = partition(s);
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].size() < result)
                result = vec[i].size();
        }
        return result - 1;
    }

    vector<vector<string> > partition(string s)
    {
        vector < vector<string> > result;
        if (s.size() == 1)
        {
            result.resize(1);
            result[0].resize(1);
            result[0][0] = s;
        }
        else if (s.size() > 1)
        {
            for (int i = 1; i < s.size(); i++)
            {
                if (valid(s.substr(0, i)))
                {
                    vector < vector<string> > tmp;
                    string sub = s.substr(i, s.size() - i);
                    tmp = partition(sub);

                    if (tmp.size())
                    {
                        int originalSize = result.size();
                        int newSize = originalSize + tmp.size();
                        result.resize(newSize);

                        for (int j = 0; j < tmp.size(); j++)
                        {
                            result[j + originalSize].push_back(s.substr(0, i));

                            for (int k = 0; k < tmp[j].size(); k++)
                            {
                                result[j + originalSize].push_back(tmp[j][k]);
                            }
                        }
                    }
                }
            }

            if (valid(s))
            {
                result.resize(result.size() + 1);
                result[result.size() - 1].push_back(s);
            }
        }
        return result;
    }

    bool valid(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
