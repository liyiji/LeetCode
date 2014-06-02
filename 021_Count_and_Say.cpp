/*
 * Count and Say
 * Total Accepted: 9081 Total Submissions: 34097
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */
class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 0; i < n - 1; i++)
        {
            s = getNext(s);
        }
        return s;
    }

    string getNext(string s)
    {
        string re;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] != s[j])
                {
                    re.append(itoa(j - i));
                    re.push_back(s[i]);
                    i = j - 1;
                    break;
                }

                if (j == s.size() - 1)
                {
                    re.append(itoa(j - i + 1));
                    re.push_back(s[i]);
                    i = j;
                    break;
                }
            }
        }
        return re;
    }

    string itoa(int i)
    {
        string re;
        do
        {
            re.push_back(i % 10 + '0');
            i /= 10;
        } while (i);

        for (int j = 0; j < re.size() / 2; j++)
        {
            swap(re[j], re[re.size() - 1 - j]);
        }

        return re;
    }
};
