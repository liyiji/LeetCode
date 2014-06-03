/*
 * Palindrome Number
 * Total Accepted: 13315 Total Submissions: 45677
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * click to show spoilers.
 * Some hints:
 *
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 *
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 *
 */
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false; // negative numbers is not Palindrome by LeetCode's rule.

        int tmp = x;
        int p = 0;
        while (tmp)
        {
            tmp /= 10;
            p++;
        }

        for (int i = 0; i < p / 2; i++)
        {
            int t1 = (x / pow10(i)) % 10;
            int t2 = (x / pow10(p - i - 1)) % 10;
            if (t1 != t2)
                return false;
        }

        return true;
    }

    int pow10(int n)
    {
        int sum = 1;
        for (int i = 0; i < n; i++)
        {
            sum *= 10;
        }
        return sum;
    }
};
