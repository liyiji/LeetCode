/*
 * Valid Parentheses
 * Total Accepted: 11589 Total Submissions: 41698
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
class Solution
{
public:
    bool isValid(string s)
    {
        string stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (isLeft(s[i]))
            {
                stack.push_back(s[i]);
            }
            else if (isRight(s[i]))
            {
                if (stack.size() == 0)
                    return false;
                char c = stack[stack.size() - 1];
                stack.resize(stack.size() - 1);
                if (match(c, s[i]) == false)
                    return false;
            }
        }
        if (stack.size())
            return false;

        return true;
    }

    bool isLeft(char c)
    {
        if (c == '{' || c == '[' || c == '(')
            return true;
        return false;
    }

    bool isRight(char c)
    {
        if (c == '}' || c == ']' || c == ')')
            return true;
        return false;
    }

    bool match(char l, char r)
    {
        if (l == '{' && r == '}')
            return true;
        if (l == '[' && r == ']')
            return true;
        if (l == '(' && r == ')')
            return true;
        return false;
    }
};
