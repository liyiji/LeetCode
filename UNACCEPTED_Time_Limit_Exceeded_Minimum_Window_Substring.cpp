/*
 * Minimum Window Substring
 * Total Accepted: 8865 Total Submissions: 50613
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
        if (S.size() < T.size())
            return string("");

        int lackCount = T.size();

        vector < size_t > charShouldCount(58, 0);
        for (size_t i = 0; i < T.size(); i++)
        {
            charShouldCount[T[i] - 'A']++;
        }

        vector < size_t > curCharCount(58, 0);
        string result = "";
        vector < size_t > matchIndicesInT;
        vector < size_t > matchIndicesInS;

        for (size_t indexInS = 0; indexInS <= S.size() - T.size(); indexInS++)
        {
            size_t indexInT = S[indexInS] - 'A';
            if (charShouldCount[indexInT] == 0)
                continue;

            // S[indexInS] is in T
            matchIndicesInT.push_back(indexInT);
            matchIndicesInS.push_back(indexInS);

            if (curCharCount[indexInT] < charShouldCount[indexInT])
            {
                lackCount--;
            }
            curCharCount[indexInT]++;

            // if the count of the last char is bigger then required and the last char is the same to the first char
            if ((curCharCount[indexInT] > charShouldCount[indexInT]) && (matchIndicesInT[matchIndicesInT.size() - 1] == matchIndicesInT[0]))
            {
                curCharCount[indexInT]--;
                matchIndicesInT.erase(matchIndicesInT.begin());
                matchIndicesInS.erase(matchIndicesInS.begin());

                // remove needless head chars looply
                while (matchIndicesInT.size())
                {
                    size_t firstIndex = matchIndicesInT[0];
                    if (curCharCount[firstIndex] <= charShouldCount[firstIndex])
                        break;

                    curCharCount[firstIndex]--;
                    matchIndicesInT.erase(matchIndicesInT.begin());
                    matchIndicesInS.erase(matchIndicesInS.begin());
                }
            }

            // find one of the results
            if (lackCount == 0)
            {
                if (result.empty() || 1 + indexInS - matchIndicesInS[0] < result.size())
                {
                    result = S.substr(matchIndicesInS[0], 1 + indexInS - matchIndicesInS[0]);
                    if (result.size() == T.size())
                        break;
                }
                else
                {
                    // remove first and continue to loop
                    size_t firstIndex = matchIndicesInT[0];
                    curCharCount[firstIndex]--;
                    lackCount++;
                    matchIndicesInT.erase(matchIndicesInT.begin());
                    matchIndicesInS.erase(matchIndicesInS.begin());
                }
            }
        }

        return result;
    }
};
