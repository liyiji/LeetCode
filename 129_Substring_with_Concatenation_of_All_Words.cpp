/*
 * Substring with Concatenation of All Words
 * Total Accepted: 9040 Total Submissions: 50795
 *
 * You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 *
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 */
class Solution
{
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        vector<int> result;
        if (L.empty())
            return result;
        if (S.size() < L.size() * L[0].size())
            return result;

        int wordLength = L[0].size();
        int wordCount = L.size();
        sort(L.begin(), L.end());

        vector<int> indices;
        for (size_t i = 0; i <= S.size() - L[0].size(); ++i)
        {
            string subS = S.substr(i, wordLength);
            pair<vector<string>::iterator, vector<string>::iterator> bound = equal_range(L.begin(), L.end(), subS);
            if (bound.first == bound.second)
            {
                indices.push_back(-1);
            }
            else
            {
                indices.push_back(bound.first - L.begin());
            }
        }

        vector<int> subIndices;
        for (size_t i = 0; i <= (S.size() - wordLength * wordCount); ++i)
        {
            bool bFirstlyPass = true;
            subIndices.clear();

            for (size_t j = 0; j < wordCount; ++j)
            {
                if (indices[j * wordLength + i] == -1)
                {
                    bFirstlyPass = false;
                    for (size_t k = 0; k < j; ++k)
                    {
                        indices[j * wordLength + i] = -1;
                    }
                    break;
                }
                else
                {
                    subIndices.push_back(indices[j * wordLength + i]);
                }
            }

            if (bFirstlyPass)
            {
                sort(subIndices.begin(), subIndices.end());

                bool bSecondlyPass = true;
                for (size_t j = 1; j < subIndices.size(); ++j)
                {
                    if (subIndices[j] == subIndices[j - 1])
                    {
                        if (L[j] != L[j - 1])
                        {
                            bSecondlyPass = false;
                            break;
                        }
                    }
                }
                if (bSecondlyPass)
                    result.push_back(i);
            }
        }

        return result;
    }
};
