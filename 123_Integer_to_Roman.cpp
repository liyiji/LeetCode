/*
 * Integer to Roman
 * Total Accepted: 9848 Total Submissions: 30104
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        int pow = 1;
        while (true)
        {
            if ((num / pow) == 0)
                break;
            pow *= 10;
            int yushu = (num % pow - num % (pow / 10)) / (pow / 10);
            string sub = numberToRoman(yushu, pow);
            result = sub + result;
        }
        return result;
    }

    string numberToRoman(int num, int pow)
    {
        string result;
        if (num > 9 || num < 1)
            return result;
        char I, V, X;
        if (pow == 10)
        {
            I = 'I';
            V = 'V';
            X = 'X';
        }
        else if (pow == 100)
        {
            I = 'X';
            V = 'L';
            X = 'C';
        }
        else if (pow == 1000)
        {
            I = 'C';
            V = 'D';
            X = 'M';
        }
        else if (pow == 10000)
        {
            I = 'M';
        }
        else
        {
            return result;
        }

        switch (num)
        {
        case 1:
            {
                result.push_back(I);
            }
            break;
        case 2:
            {
                result.push_back(I);
                result.push_back(I);
            }
            break;
        case 3:
            {
                result.push_back(I);
                result.push_back(I);
                result.push_back(I);
            }
            break;
        case 4:
            {
                result.push_back(I);
                result.push_back(V);
            }
            break;
        case 5:
            {
                result.push_back(V);
            }
            break;
        case 6:
            {
                result.push_back(V);
                result.push_back(I);
            }
            break;
        case 7:
            {
                result.push_back(V);
                result.push_back(I);
                result.push_back(I);
            }
            break;
        case 8:
            {
                result.push_back(V);
                result.push_back(I);
                result.push_back(I);
                result.push_back(I);
            }
            break;
        case 9:
            {
                result.push_back(I);
                result.push_back(X);
            }
            break;
        default:
            {
            }
            break;
        }
        return result;
    }
};
