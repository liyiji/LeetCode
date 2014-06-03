/*
 * Reverse Integer
 * Total Accepted: 14878 Total Submissions: 35753
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 * Have you thought about this?
 *
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 *
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 *
 * Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
 *
 */
class Solution
{
public:
    int reverse(int x)
    {
        bool biggerThan0 = true;
        if (x < 0)
            biggerThan0 = false;

        int bak = abs(x);
        vector<int> vec;
        do
        {
            vec.push_back(bak % 10);
            bak /= 10;
        } while (bak);

        for (int i = vec.size() - 1; i >= 0; i--)
        {
            int tmp = bak;
            bak += (vec[i] * pow(10, vec.size() - i - 1));
            if (fabs(double(bak) - double(tmp) - double(vec[i] * pow(10, vec.size() - i - 1))) > 0.9)
                return 0;
        }

        if (biggerThan0 == false)
            return -bak;
        else
            return bak;
    }
};
