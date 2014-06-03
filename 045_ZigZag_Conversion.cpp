/*
 * ZigZag Conversion
 * Total Accepted: 7793 Total Submissions: 33632
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
class Solution
{
public:
    string convert(string s, int nRows)
    {
        if (nRows == 1)
            return s;

        vector < string > vec(nRows);
        int single = 2 * nRows - 2;
        int n = s.size() / single;
        int remainCount = s.size() - (s.size() / single * single);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nRows; j++)
            {
                if (j == 0)
                {
                    vec[j].push_back(s[single * i]);
                }
                else if (j == nRows - 1)
                {
                    vec[j].push_back(s[single * i + (nRows - 1)]);
                }
                else
                {
                    vec[j].push_back(s[single * i + (nRows - 1) - (nRows - 1 - j)]);
                    vec[j].push_back(s[single * i + (nRows - 1) + (nRows - 1 - j)]);
                }
            }
        }

        if (remainCount)
        {
            for (int j = 0; j < nRows; j++)
            {
                if (j == 0)
                {
                    if (single * n < s.size())
                        vec[j].push_back(s[single * n]);
                }
                else if (j == nRows - 1)
                {
                    if (single * n + (nRows - 1) < s.size())
                        vec[j].push_back(s[single * n + (nRows - 1)]);
                }
                else
                {
                    if (single * n + (nRows - 1) - (nRows - 1 - j) < s.size())
                        vec[j].push_back(s[single * n + (nRows - 1) - (nRows - 1 - j)]);
                    if (single * n + (nRows - 1) + (nRows - 1 - j) < s.size())
                        vec[j].push_back(s[single * n + (nRows - 1) + (nRows - 1 - j)]);
                }
            }
        }

        string result;
        for (int i = 0; i < nRows; i++)
        {
            result.append(vec[i]);
        }

        return result;
    }
};
