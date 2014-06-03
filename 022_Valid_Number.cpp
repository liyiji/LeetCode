/*
 * Valid Number
 * Total Accepted: 6561 Total Submissions: 61273
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */
class Solution
{
public:
    bool isNumber(const char *s)
    {
        string str;

        // remove spaces in the head and tail of the string
        // and confirm there are no spaces in the middle of the string
        // confirm there is at most a '.' and a 'e'
        bool testHead = true;
        bool testTail = false;
        int pCount = 0;
        int eCount = 0;
        for (int i = 0;; i++)
        {
            if (s[i] == '\0')
            {
                break;
            }

            if (isPoint(s[i]))
            {
                pCount++;
                if (pCount > 1)
                    return false;
            }

            if (isE(s[i]))
            {
                eCount++;
                if (eCount > 1)
                    return false;
            }

            if (testHead)
            {
                if (isSpace(s[i]) == false)
                {
                    str.push_back(s[i]);
                    testHead = false;
                }
            }
            else
            {
                if (isSpace(s[i]))
                {
                    testTail = true;
                    continue;
                }

                if (testTail == false)
                {
                    str.push_back(s[i]);
                }
                else
                {
                    if (isSpace(s[i]) == false)
                        return false;
                }
            }
        }

        if (str.size() == 0)
            return false;

        for (int i = 0; i < str.size(); i++)
        {
            if (isLetterNotE(str[i]) || isSpace(str[i]))
                return false;
        }

        if (isInt(str) || isFloat(str) || isFloatWithE(str))
            return true;

        return false;
    }

    bool isInt(string str)
    {
        bool b = true;
        bool bHaveDigit = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (bHaveDigit == false && isDigit(str[i]))
            {
                bHaveDigit = true;
            }

            if (i == 0)
            {
                if (isDigit(str[i]) == false && isPM(str[i]) == false)
                {
                    b = false;
                    break;
                }
            }
            else
            {
                if (isDigit(str[i]) == false)
                {
                    b = false;
                    break;
                }
            }
        }

        if (bHaveDigit)
            return b;
        else
            return false;
    }

    bool isFloat(string str)
    {
        bool bHaveDigit = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (bHaveDigit == false && isDigit(str[i]))
            {
                bHaveDigit = true;
            }

            if (i == 0)
            {
                if (isPM(str[i]) == false && isDigit(str[i]) == false && isPoint(str[i]) == false)
                {
                    return false;
                }
            }
            else
            {
                if (isDigit(str[i]) == false && isPoint(str[i]) == false)
                {
                    return false;
                }
            }
        }

        if (bHaveDigit == false)
        {
            return false;
        }

        return true;
    }

    bool isFloatWithE(string str)
    {
        int eisi = -1;
        for (int i = 0; i < str.size(); i++)
        {
            if (isE(str[i]))
            {
                eisi = i;
                break;
            }
        }
        if (eisi == -1 || eisi == 0 || eisi == str.size() - 1)
        {
            return false;
        }

        string str1 = str.substr(0, eisi);
        string str2 = str.substr(eisi + 1, str.size() - 1 - eisi);

        bool b1 = isFloat(str1);
        bool b2 = isInt(str2);
        return b1 && b2;
    }

    bool isDigit(char a)
    {
        if (a >= '0' && a <= '9')
            return true;
        return false;
    }

    bool isPoint(char a)
    {
        if (a == '.')
            return true;
        return false;
    }

    bool isE(char a)
    {
        if (a == 'e' || a == 'E')
            return true;
        return false;
    }

    bool isLetter(char a)
    {
        if (a >= 'a' && a <= 'z')
            return true;
        if (a >= 'A' && a <= 'Z')
            return true;
        return false;
    }

    bool isLetterNotE(char a)
    {
        bool b = isLetter(a);
        bool be = isE(a);
        if (b && !be)
            return true;
        return false;
    }

    bool isSpace(char a)
    {
        if (a == ' ' || a == '\t')
            return true;
        return false;
    }

    bool isPM(char a) // Plus or minus
    {
        if (a == '+' || a == '-')
            return true;
        return false;
    }
};
