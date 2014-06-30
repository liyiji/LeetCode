/*
 * Longest Palindromic Substring
 * Total Accepted: 12095 Total Submissions: 59665
 *
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        string uniqueChars;
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (i == 0)
            {
                if (tmp[i] != tmp[i + 1])
                    uniqueChars.push_back(tmp[i]);
            }
            else if (i + 1 == tmp.size())
            {
                if (tmp[i] != tmp[i - 1])
                    uniqueChars.push_back(tmp[i]);
            }
            else
            {
                if ((tmp[i] != tmp[i + 1]) && (tmp[i] != tmp[i - 1]))
                    uniqueChars.push_back(tmp[i]);
            }
        }
#ifdef liyijiDebug
        cout << tmp << " " << uniqueChars << endl;
#endif

        // pair mean subStartIndex and subEndIndex
        vector < pair<int, int> > noUnique;
        vector < pair<int, int> > uniqueAtMiddle;

        size_t startIndex = 0;
        while (true)
        {
#ifdef liyijiDebug
            cout << "startIndex is " << startIndex << endl;
#endif
            size_t firstUniquePos = s.find_first_of(uniqueChars, startIndex);
            if (firstUniquePos == string::npos)
            {
                noUnique.push_back(make_pair(startIndex, s.size() - 1));
                break;
            }
            else
            {
                size_t secondUniquePos = s.find_first_of(uniqueChars, firstUniquePos + 1);
                if (secondUniquePos == string::npos)
                {
                    noUnique.push_back(make_pair(startIndex, firstUniquePos - 1));
                    noUnique.push_back(make_pair(firstUniquePos + 1, s.size() - 1));

                    size_t subHalfLength = min(firstUniquePos - startIndex, s.size() - 1 - firstUniquePos);
                    uniqueAtMiddle.push_back(make_pair(firstUniquePos - subHalfLength, firstUniquePos + subHalfLength));
                    break;
                }
                else
                {
                    if (startIndex + 1 <= firstUniquePos)
                        noUnique.push_back(make_pair(startIndex, firstUniquePos - 1));

                    size_t subHalfLength = min(firstUniquePos - startIndex, secondUniquePos - firstUniquePos);
                    uniqueAtMiddle.push_back(make_pair(firstUniquePos - subHalfLength, firstUniquePos + subHalfLength));

                    startIndex = firstUniquePos + 1;
                }
            }
        }
#ifdef liyijiDebug
        for (size_t i = 0; i < noUnique.size(); i++)
        {
            cout << noUnique[i].first << " " << noUnique[i].second << endl;
        }
        cout << endl;
        for (size_t i = 0; i < uniqueAtMiddle.size(); i++)
        {
            cout << uniqueAtMiddle[i].first << " " << uniqueAtMiddle[i].second << endl;
        }
#endif
        string result = string(s.substr(0, 1));
        for (size_t i = 0; i < noUnique.size(); i++)
        {
            string str = getSub1(s.substr(noUnique[i].first, noUnique[i].second - noUnique[i].first + 1), result.size());
            if (str.size() > result.size())
                result = str;
        }
        for (size_t i = 0; i < uniqueAtMiddle.size(); i++)
        {
            string str = getSub2(s.substr(uniqueAtMiddle[i].first, uniqueAtMiddle[i].second - uniqueAtMiddle[i].first + 1), result.size());
            if (str.size() > result.size())
                result = str;
        }
        return result;
    }

    string getSub1(string input, size_t curMaxSize)
    {
#ifdef liyijiDebug
        cout << "getSub1 " << input << " " << curMaxSize << endl;
#endif
        string result;
        for (size_t length = input.size(); length > curMaxSize; length--)
        {
            for (size_t startIndex = 0; startIndex + curMaxSize < input.size(); startIndex++)
            {
                if (startIndex + length > input.size())
                    break;
                result = input.substr(startIndex, length);
#ifdef liyijiDebug
//                if (input[startIndex] == 'r' || length == 7)
//                {
//                    cout << input.substr(startIndex, input.size());
//                    cout << endl;
//                }
#endif
                if (valid(result))
                {
#ifdef liyijiDebug
                    //cout << result << endl;
#endif
                    return result;
                }
            }
        }
        return "";
    }

    string getSub2(string input, size_t curMaxSize)
    {
#ifdef liyijiDebug
        cout << "getSub2 " << input << " " << curMaxSize << endl;
#endif
        string result;
        if (input.size() <= curMaxSize)
            return result;

        for (size_t i = input.size() / 2; i < input.size(); i++)
        {
            if (input[i] == input[input.size() - 1 - i])
            {
                continue;
            }
            else
            {
                if ((i - (input.size() - 1 - i) + 1) > curMaxSize)
                {
                    result = input.substr(input.size() - 1 - i, i - (input.size() - 1 - i) + 1);
                    return result;
                }
                else
                {
                    return result;
                }
            }
        }

        return input;
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
