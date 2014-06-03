/*
 * Pow(x, n)
 * Total Accepted: 14013 Total Submissions: 54122
 *
 * Implement pow(x, n).
 */
class Solution
{
public:
    double pow(double x, int n)
    {
        if (n == -1)
            return 1 / x;
        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        if (n % 2 != 0)
        {
            if (n > 0)
                return pow(x * x, n / 2) * x;
            if (n < 0)
                return pow(x * x, n / 2) / x;
        }
        else
        {
            return pow(x * x, n / 2);
        }
    }
};
