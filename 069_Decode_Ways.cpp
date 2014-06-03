/*
 * Decode Ways
 * Total Accepted: 9413 Total Submissions: 60056
 *
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */
class Solution
{
public:
    int numDecodings(string s)
    {
        int result = 0;
        switch (s.size())
        {
        case 0:
            {
                result = 0;
                break;
            }
        case 1:
            {
                if (validOne(s[0]))
                    result++;
                break;
            }
        case 2:
            {
                if (validOne(s[0]) && validOne(s[1]))
                    result++;
                if (validTwo(s[0], s[1]))
                    result++;
                break;
            }
        case 3:
            {
                if (validOne(s[0]) && validOne(s[1]) && validOne(s[2]))
                    result++;
                if (validOne(s[0]) && validTwo(s[1], s[2]))
                    result++;
                if (validTwo(s[0], s[1]) && validOne(s[2]))
                    result++;
                break;
            }
        default:
            {
                int half = s.size() / 2;
                result += (numDecodings(s.substr(0, half)) * numDecodings(s.substr(half, s.size() - half)));
                if (validTwo(s[half - 1], s[half]))
                {
                    result += (numDecodings(s.substr(0, half - 1)) * numDecodings(s.substr(half + 1, s.size() - half - 1)));
                }
                break;
            }
        }

        return result;
    }

    bool validOne(char a)
    {
        if (a - '0' >= 1 && a - '0' <= 9)
            return true;
        return false;
    }

    bool validTwo(char a, char b)
    {
        if (a - '0' == 1)
            return true;
        if (a - '0' == 2)
        {
            if (b - '0' <= 6)
                return true;
            else
                return false;
        }
        return false;
    }
};
