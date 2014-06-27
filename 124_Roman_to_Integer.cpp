/*
 * Roman to Integer
 * Total Accepted: 10305 Total Submissions: 31305
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        int cursor;
        bool bFound;
        ////////////////////////////////////////////////////////////////////////////
        bFound = false;
        for (cursor = s.size() - 1; cursor >= 0; cursor--)
        {
            if (s[cursor] == 'M')
            {
                bFound = true;
                break;
            }
        }
        if (bFound)
        {
            string sub1 = s.substr(0, cursor + 1);
            size_t CCount = 0;
            for (size_t i = 0; i < sub1.size(); i++)
            {
                if (sub1[i] == 'C')
                    CCount++;
            }
            result += (sub1.size() - CCount) * 1000 - CCount * 100;
            s = s.substr(cursor + 1, s.size() - cursor - 1);
        }
        ////////////////////////////////////////////////////////////////////////////
        bFound = false;
        for (cursor = 0; cursor < s.size(); cursor++)
        {
            if (s[cursor] == 'D')
            {
                bFound = true;
                break;
            }
        }
        if (bFound)
        {
            result += 500 - cursor * 100;
            s = s.substr(cursor + 1, s.size() - cursor - 1);
        }
        ////////////////////////////////////////////////////////////////////////////
        bFound = false;
        for (cursor = s.size() - 1; cursor >= 0; cursor--)
        {
            if (s[cursor] == 'C')
            {
                bFound = true;
                break;
            }
        }
        if (bFound)
        {
            string sub1 = s.substr(0, cursor + 1);
            size_t XCount = 0;
            for (size_t i = 0; i < sub1.size(); i++)
            {
                if (sub1[i] == 'X')
                    XCount++;
            }
            result += (sub1.size() - XCount) * 100 - XCount * 10;
            s = s.substr(cursor + 1, s.size() - cursor - 1);
        }
        ////////////////////////////////////////////////////////////////////////////
        bFound = false;
        for (cursor = 0; cursor < s.size(); cursor++)
        {
            if (s[cursor] == 'L')
            {
                bFound = true;
                break;
            }
        }
        if (bFound)
        {
            result += 50 - cursor * 10;
            s = s.substr(cursor + 1, s.size() - cursor - 1);
        }
        ////////////////////////////////////////////////////////////////////////////
        bFound = false;
        for (cursor = s.size() - 1; cursor >= 0; cursor--)
        {
            if (s[cursor] == 'X')
            {
                bFound = true;
                break;
            }
        }
        if (bFound)
        {
            string sub1 = s.substr(0, cursor + 1);
            size_t ICount = 0;
            for (size_t i = 0; i < sub1.size(); i++)
            {
                if (sub1[i] == 'I')
                    ICount++;
            }
            result += (sub1.size() - ICount) * 10 - ICount * 1;
            s = s.substr(cursor + 1, s.size() - cursor - 1);
        }
        ////////////////////////////////////////////////////////////////////////////
        bFound = false;
        for (cursor = 0; cursor < s.size(); cursor++)
        {
            if (s[cursor] == 'V')
            {
                bFound = true;
                break;
            }
        }
        if (bFound)
        {
            result += 5 - cursor * 1;
            s = s.substr(cursor + 1, s.size() - cursor - 1);
        }
        ////////////////////////////////////////////////////////////////////////////
        result += s.size();
        ////////////////////////////////////////////////////////////////////////////
        return result;
    }
};
