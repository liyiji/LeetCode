/*
 * Evaluate Reverse Polish Notation
 * Total Accepted: 13727 Total Submissions: 70275
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 */
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        tokens.push_back("end");

        while (tokens.front() != "end")
        {
            if (isOperator(tokens.front()))
            {
                string str2 = tokens.back();
                tokens.pop_back();
                string str1 = tokens.back();
                tokens.pop_back();
                string strOperator = tokens.front();
                tokens.erase(tokens.begin());
                int a1 = atoi(str1.data());
                int a2 = atoi(str2.data());
                int re = pmmd(a1, a2, strOperator);
                stringstream strStream;
                strStream << re;
                string strResult = strStream.str();
                tokens.push_back(strResult);
            }
            else
            {
                tokens.push_back(tokens.front());
                tokens.erase(tokens.begin());
            }
        }

        string str = tokens.back();
        int result = atoi(str.data());
        return result;
    }

    bool isOperator(string str)
    {
        if (str != "+" && str != "-" && str != "*" && str != "/")
            return false;
        return true;
    }

    int pmmd(int a1, int a2, string strOperator)
    {
        if (strOperator == "+")
        {
            return a1 + a2;
        }
        else if (strOperator == "-")
        {
            return a1 - a2;
        }
        else if (strOperator == "*")
        {
            return a1 * a2;
        }
        else if (strOperator == "/")
        {
            return a1 / a2;
        }
    }
};
