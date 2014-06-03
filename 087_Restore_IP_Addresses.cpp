/*
 * Restore IP Addresses
 * Total Accepted: 8439 Total Submissions: 41996
 *
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string > result;

        int n = s.size();
        if (n > 12 || n < 4)
            return result;

        for (int i1 = 1; i1 <= 3; i1++)
        {
            for (int i2 = 1; i2 <= 3; i2++)
            {
                for (int i3 = 1; i3 <= 3; i3++)
                {
                    for (int i4 = 1; i4 <= 3; i4++)
                    {
                        if (i1 + i2 + i3 + i4 != n)
                            continue;

                        string s1 = s.substr(0, i1);
                        if (isValidSub(s1) == false)
                            continue;
                        string s2 = s.substr(i1, i2);
                        if (isValidSub(s2) == false)
                            continue;
                        string s3 = s.substr(i1 + i2, i3);
                        if (isValidSub(s3) == false)
                            continue;
                        string s4 = s.substr(i1 + i2 + i3, i4);
                        if (isValidSub(s4) == false)
                            continue;

                        result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
    }

    bool isValidSub(string s)
    {
        if (s.size() > 3 || s.size() < 1 || (s.size() != 1 && s[0] == '0'))
            return false;
        if (s.size() == 1 || s.size() == 2)
            return true;
        if (s.size() == 3)
        {
            if (s[0] == '1')
                return true;
            if (s[0] == '2')
            {
                if (s[1] < '5')
                    return true;
                else if (s[1] > '5')
                    return false;
                else // s[1] == '5'
                {
                    if (s[2] < '6')
                        return true;
                    else
                        return false;
                }
            }
        }
        return false;
    }
};
