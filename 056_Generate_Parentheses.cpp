/*
 * Generate Parentheses
 * Total Accepted: 12476 Total Submissions: 40362
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (n == 0)
            return result;

        string l = "(";
        string r = ")";
        result.push_back(l);
        vector<int> lc(1, 1);
        vector<int> rc(1, 0);

        while (true)
        {
            bool bHaveChange = false;
            for (int i = 0; i < result.size(); i++)
            {
                if (lc[i] == rc[i])
                {
                    if (rc[i] == n)
                    {
                        continue;
                    }
                    else if (lc[i] < n)
                    {
                        result[i].append(l);
                        lc[i]++;
                        bHaveChange = true;
                    }
                }
                else if (lc[i] > rc[i])
                {
                    if (lc[i] == n)
                    {
                        result[i].append(r);
                        rc[i]++;
                        bHaveChange = true;
                    }
                    else if (lc[i] < n)
                    {
                        result.push_back(result[i]);
                        lc.push_back(lc[i]);
                        rc.push_back(rc[i]);

                        result[i].append(l);
                        lc[i]++;

                        result[result.size() - 1].append(r);
                        rc[rc.size() - 1]++;
                        bHaveChange = true;
                    }
                }
            }
            if (bHaveChange == false)
            {
                break;
            }
        }
        return result;
    }
};
