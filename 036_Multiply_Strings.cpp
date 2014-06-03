/*
 * Multiply Strings
 * Total Accepted: 7953 Total Submissions: 39775
 *
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 */
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> mid(n1 + n2, 0);

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                mid[i + j + 1] += ((num1[i] - '0') * (num2[j] - '0'));
            }
        }

        string result = regulate(mid);
        return result;
    }

    string regulate(vector<int> mid)
    {
        int n = mid.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (mid[i] > 9)
            {
                mid[i - 1] += mid[i] / 10;
                mid[i] %= 10;
            }
        }

        int start = 0;
        for (int i = 0; i < n; i++)
        {
            start = i;
            if (mid[i] != 0)
            {
                break;
            }
        }

        string result;
        for (int i = start; i < n; i++)
        {
            result.push_back(mid[i] + '0');
        }

        if (result.size() == 0)
        {
            result.push_back('0');
        }
        return result;
    }
};
