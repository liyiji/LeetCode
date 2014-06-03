/*
 * Add Binary
 * Total Accepted: 10288 Total Submissions: 40614
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        char c = '0';
        while (a.size() || b.size())
        {
            char ca = '0';
            if (a.size())
            {
                ca = a[a.size() - 1];
                a.erase(a.end() - 1);
            }
            char cb = '0';
            if (b.size())
            {
                cb = b[b.size() - 1];
                b.erase(b.end() - 1);
            }

            if (ca + cb + c == '1' + '1' + '1')
            {
                c = '1';
                result.insert(result.begin(), '1');
            }
            else if (ca + cb + c == '1' + '1' + '0')
            {
                c = '1';
                result.insert(result.begin(), '0');
            }
            else if (ca + cb + c == '1' + '0' + '0')
            {
                c = '0';
                result.insert(result.begin(), '1');
            }
            else if (ca + cb + c == '0' + '0' + '0')
            {
                c = '0';
                result.insert(result.begin(), '0');
            }
        }

        if (c == '1')
        {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};
