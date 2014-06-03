/*
 * Valid Palindrome
 * Total Accepted: 12179 Total Submissions: 55178
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (j >= i)
        {
            if (isAbcOrNum(s[j]) == false)
            {
                j--;
                continue;
            }
            if (isAbcOrNum(s[i]) == false)
            {
                i++;
                continue;
            }
            if (isEqual(s[i], s[j]) == false)
            {
                return false;
            }
            else
            {
                j--;
                i++;
            }
        }
        return true;
    }

    bool isAbcOrNum(char a)
    {
        if (a >= 'a' && a <= 'z')
            return true;
        if (a >= 'A' && a <= 'Z')
            return true;
        if (a >= '0' && a <= '9')
            return true;
        return false;
    }

    bool isEqual(char a, char b)
    {
        if (a >= 'a' && a <= 'z')
        {
            if (b >= 'a' && b <= 'z')
            {
                if (b == a)
                    return true;
            }
            if (b >= 'A' && b <= 'Z')
            {
                if (b - 'A' == a - 'a')
                    return true;
            }
        }
        if (a >= 'A' && a <= 'Z')
        {
            if (b >= 'A' && b <= 'Z')
            {
                if (b == a)
                    return true;
            }
            if (b >= 'a' && b <= 'z')
            {
                if (b - 'a' == a - 'A')
                    return true;
            }
        }
        if (a >= '0' && a <= '9')
        {
            if (b == a)
                return true;
        }

        return false;
    }
};
