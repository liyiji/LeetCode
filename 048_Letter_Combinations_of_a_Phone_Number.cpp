/*
 * Letter Combinations of a Phone Number
 * Total Accepted: 10191 Total Submissions: 39334
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        int strCount = 1;
        for (int i = 0; i < digits.size(); i++)
        {
            strCount *= nn(digits[i] - '0');
        }
        vector<string> result(strCount);

        int layerCount = strCount;
        for (int i = 0; i < digits.size(); i++)
        {
            string houxuan = ss(digits[i] - '0');
            char pend = houxuan[houxuan.size() - 1];

            int loopCount = nn(digits[i] - '0');
            layerCount = layerCount / loopCount;

            for (int j = 0; j < strCount; j++)
            {
                if (j % layerCount == 0)
                {
                    pend = next(pend);
                }
                result[j].push_back(pend);
            }
        }

        return result;
    }

    string ss(int digit)
    {
        switch (digit)
        {
        case 2:
            return "abc";
        case 3:
            return "def";
        case 4:
            return "ghi";
        case 5:
            return "jkl";
        case 6:
            return "mno";
        case 7:
            return "pqrs";
        case 8:
            return "tuv";
        case 9:
            return "wxyz";
        default:
            return "";
        }
    }

    char next(char input)
    {
        switch (input)
        {
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'v':
            return input - 2;
        case 's':
        case 'z':
            return input - 3;
        default:
            return input + 1;
        }
    }

    int nn(int digit)
    {
        switch (digit)
        {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            return 3;
        case 7:
        case 9:
            return 4;
        default:
            return 0;
        }
    }
};
