/*
 * Divide Two Integers
 * Total Accepted: 10397 Total Submissions: 65967
 *
 * Divide two integers without using multiplication, division and mod operator.
 */
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;

        int a = dividend;
        int b = divisor;

        bool bSameSign = true;
        bool bBothPosi = false;
        if (dividend > 0)
        {
            if (divisor > 0)
            {
                bBothPosi = true;
            }
            else if (divisor < 0)
            {
                bSameSign = false;
            }
        }
        else if (dividend < 0)
        {
            if (divisor > 0)
                bSameSign = false;
        }

        if (bBothPosi)
        {
            a = abs(dividend);
            b = abs(divisor);
            if (a < b)
                return 0;
        }
        else
        {
            a = -abs(dividend);
            b = -abs(divisor);
            if (a > b)
                return 0;
        }

        int result = 0;
        while (true)
        {
            int tmp = b;
            int bei = 1;
            if (bBothPosi)
            {
                while ((tmp << 1) > tmp && (tmp << 1) <= a)
                {
                    tmp = tmp << 1;
                    bei += bei;
                }
                a = a - tmp;
                result += bei;
                if (a < b)
                    break;
            }
            else
            {
                while ((tmp << 1) < tmp && (tmp << 1) >= a)
                {
                    tmp = tmp << 1;
                    bei += bei;
                }
                a = a - tmp;
                result += bei;
                if (a > b)
                    break;
            }
        }

        if (bSameSign == false)
            return -result;
        else
            return result;
    }
};
