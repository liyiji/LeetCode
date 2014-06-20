/*
 * Combination Sum II
 * Total Accepted: 9668 Total Submissions: 39956
 *
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 *
 *     All numbers (including target) will be positive integers.
 *     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *     The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 */
class Solution
{
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target)
    {
        vector < vector<int> > result;
        if (num.empty())
            return result;

        sort(num.begin(), num.end());

        int maxItemCount = target / num[0];
        for (int itemCount = 1; itemCount <= maxItemCount; itemCount++)
        {
            vector < vector<int> > subResult = getSub(num, target, itemCount, 0);
            for (size_t i = 0; i < subResult.size(); i++)
            {
                result.push_back(subResult[i]);
            }
        }

        sort(result.begin(), result.end());
        vector<vector<int> >::iterator it = unique(result.begin(), result.end());
        result.resize(it - result.begin());
        return result;
    }

    vector<vector<int> > getSub(const vector<int> &num, int target, int itemCount, int startIndex)
    {
        if (target <= 0 || itemCount <= 0 || startIndex >= num.size() || num[startIndex] > target)
            return vector<vector<int> >();

        if (itemCount == 1)
        {
            if (find(num.begin() + startIndex, num.end(), target) != num.end())
            {
                vector < vector<int> > result(1, vector<int>(1, target));
                return result;
            }
        }
        vector < vector<int> > sub1 = getSub(num, target - num[startIndex], itemCount - 1, startIndex + 1);
        vector < vector<int> > sub2 = getSub(num, target, itemCount, startIndex + 1);

        for (size_t i = 0; i < sub1.size(); i++)
        {
            sub1[i].insert(sub1[i].begin(), num[startIndex]);
        }
        for (size_t i = 0; i < sub2.size(); i++)
        {
            sub1.push_back(sub2[i]);
        }

        return sub1;
    }
};
