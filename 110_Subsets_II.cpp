/*
 * Subsets II
 * Total Accepted: 11105 Total Submissions: 41620
 *
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 *
 * Note:
 *
 *     Elements in a subset must be in non-descending order.
 *     The solution set must not contain duplicate subsets.
 *
 * For example,
 * If S = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 */
class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        sort(S.begin(), S.end());

        vector < vector<int> > result;
        result.push_back(vector<int>());
        if (S.size() == 0)
            return result;

        result.push_back(S);
        if (S.size() == 1)
            return result;

        for (size_t subSetItemCount = 1; subSetItemCount < S.size(); subSetItemCount++)
        {
            vector < vector<int> > sub = calcSub(S, 0, S.size() - 1, subSetItemCount);
            for (size_t j = 0; j < sub.size(); j++)
            {
                result.push_back(sub[j]);
            }
        }

        return result;
    }

    vector<vector<int> > calcSub(const vector<int> &S, int start, int end, int n)
    {
        vector < vector<int> > result;
        if (n > end - start + 1)
        {
            return result;
        }

        if (n == end - start + 1)
        {
            vector<int> sub;
            for (size_t i = start; i <= end; i++)
            {
                sub.push_back(S[i]);
            }
            result.push_back(sub);
            return result;
        }

        if (n == 0)
        {
            result.push_back(vector<int>());
            return result;
        }

        if (n == 1)
        {
            result.push_back(vector<int>(1, S[start]));
            for (size_t i = start; i <= end; i++)
            {
                if (S[i] != result[result.size() - 1][0])
                {
                    result.push_back(vector<int>(1, S[i]));
                }
            }
            return result;
        }

        int cursor = start;
        while (cursor <= end)
        {
            if (S[cursor] == S[start])
                cursor++;
            else
                break;
        }
        cursor--;

        int firstNumberCount = cursor - start + 1;
        for (size_t i = 0; i < firstNumberCount; i++)
        {
            if (n - i - 1 > 0)
            {
                vector < vector<int> > sub = calcSub(S, cursor + 1, end, n - 1 - i);
                for (size_t j = 0; j < sub.size(); j++)
                {
                    for (size_t k = 0; k < i + 1; k++)
                    {
                        sub[j].insert(sub[j].begin(), S[start]);
                    }
                }

                for (size_t j = 0; j < sub.size(); j++)
                {
                    result.push_back(sub[j]);
                }
            }
            else if (n - i - 1 == 0)
            {
                result.push_back(vector<int>(n, S[start]));
                break;
            }
        }

        vector < vector<int> > noFirstNumberResult = calcSub(S, cursor + 1, end, n);
        for (size_t i = 0; i < noFirstNumberResult.size(); i++)
        {
            result.push_back(noFirstNumberResult[i]);
        }

        return result;
    }
};
