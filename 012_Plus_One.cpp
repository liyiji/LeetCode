/*
 * Plus One
 * Total Accepted: 11841 Total Submissions: 38528
 *
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        digits[digits.size() - 1] += 1;
        for (int i = digits.size() - 1; i > 0; i--)
        {
            if (digits[i] > 9)
            {
                int yushu = digits[i] % 10;
                int jinwei = digits[i] / 10;
                digits[i] = yushu;
                digits[i - 1] += jinwei;
            }
        }
        if (digits[0] > 9)
        {
            int yushu = digits[0] % 10;
            int jinwei = digits[0] / 10;
            digits[0] = yushu;
            digits.insert(digits.begin(), jinwei);
        }
        return digits;
    }
};
