/*
 * Minimum Window Substring
 * Total Accepted: 9989 Total Submissions: 56242
 *
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 *
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
class Solution
{
public:
    // Tips: characters in T could be duplicate.
    string minWindow(string S, string T)
    {
        const int charactorCount = 'z' + 1 - 'A';
        if (S.size() < T.size())
            return string("");

        int lackCount = T.size();

        vector<size_t> charExpectCount(charactorCount, 0);
        for (size_t i = 0; i < T.size(); i++)
        {
            charExpectCount[T[i] - 'A']++;
        }

        vector<size_t> curCharCount(charactorCount, 0);
        string result = "";
        vector<size_t> matchIndicesInT;
        vector<size_t> matchIndicesInS;

        for (size_t indexInS = 0; indexInS < S.size(); indexInS++)
        {
            size_t indexInT = S[indexInS] - 'A';
            if (charExpectCount[indexInT] == 0)
                continue;

            // S[indexInS] is in T
            matchIndicesInT.push_back(indexInT);
            matchIndicesInS.push_back(indexInS);

            if (curCharCount[indexInT] < charExpectCount[indexInT])
            {
                lackCount--;
            }
            curCharCount[indexInT]++;

            // find one of the results
            if (lackCount == 0)
            {
                // shrink
                while (matchIndicesInT.size())
                {
                    char firstChar = S[matchIndicesInS[0]];
                    if (curCharCount[firstChar - 'A'] > charExpectCount[firstChar - 'A'])
                    {
                        curCharCount[firstChar - 'A']--;
                        matchIndicesInT.erase(matchIndicesInT.begin());
                        matchIndicesInS.erase(matchIndicesInS.begin());
                    }
                    else
                    {
                        break;
                    }
                }

                if (result.empty() || 1 + indexInS - matchIndicesInS[0] < result.size())
                {
                    result = S.substr(matchIndicesInS[0], 1 + indexInS - matchIndicesInS[0]);
                    if (result.size() == T.size())
                        break;
                }

                // remove first and continue to loop
                size_t firstIndex = matchIndicesInT[0];
                curCharCount[firstIndex]--;
                lackCount++;
                matchIndicesInT.erase(matchIndicesInT.begin());
                matchIndicesInS.erase(matchIndicesInS.begin());
            }
        }

        return result;
    }
};
