/*
 * Gray Code
 * Total Accepted: 9979 Total Submissions: 31469
 *
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        result.push_back(0);
        if (n == 0)
            return result;

        result.push_back(1);
        if (n == 1)
            return result;

        for (int i = 2; i <= n; i++)
        {
            int plus = pow(2, i - 1);
            vector<int> tmp(result);
            for (int j = 0; j < tmp.size(); j++)
                tmp[j] += plus;
            for (int j = 0; j < plus; j++)
                result.push_back(tmp[plus - j - 1]);
        }
        return result;
    }
};
