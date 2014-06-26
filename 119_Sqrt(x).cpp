/*
 * Sqrt(x)
 * Total Accepted: 15923 Total Submissions: 73014
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 */
class Solution
{
public:
    int sqrt(int x)
    {
        if (x == 0)
            return x;
        double t = (double(x)) / 2;
        double t2 = (t / 2) + (double(x)) / (2 * t);
        while (abs(t - t2) >= 1)
        {
            t = t2;
            t2 = (t / 2) + (double(x)) / (2 * t);
        }
        return int(t2);
    }
};
