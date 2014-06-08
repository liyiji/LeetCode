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
        for (int length = s.size(); length >= 1; length--)
        {
//            cout << "Length = " << length << endl;
            for (int start = 0; start <= s.size() - length; start++)
            {
                int end = start + length - 1;
//                cout << "      Start = " << start << endl;
//                cout << "      End   = " << end << endl;
                for (int i = start; i < (start + end + 1) / 2; i++)
                {
//                    cout << "          i = " << i << endl;
                    if (s[i] != s[end - i])
                    {
//                        cout << s[i] << s[end - i] << endl;
                        break;
                    }
                    if (i + 1 >= (start + end + 1) / 2)
                    {
                        string result = s.substr(start, length);
//                        cout << start << " " << length << endl;
                        return result;
                    }
                }
            }
        }
        return "";
    }
};
