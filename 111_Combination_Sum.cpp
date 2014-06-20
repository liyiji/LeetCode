/*
 * Combination Sum
 * Total Accepted: 12390 Total Submissions: 47238
 *
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 *
 *     All numbers (including target) will be positive integers.
 *     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *     The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 */
class Solution
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector < vector<int> > result;
        if (candidates.empty())
            return result;

        sort(candidates.begin(), candidates.end());

        int maxItemCount = target / candidates[0];
        for (int itemCount = 1; itemCount <= maxItemCount; itemCount++)
        {
            vector < vector<int> > subResult = getSub(candidates, target, itemCount, 0);
            for (size_t i = 0; i < subResult.size(); i++)
            {
                result.push_back(subResult[i]);
            }
        }

        return result;
    }

    vector<vector<int> > getSub(const vector<int> &candidates, int target, int itemCount, int startIndex)
    {
        if (target <= 0 || itemCount <= 0 || startIndex >= candidates.size() || candidates[startIndex] > target)
            return vector<vector<int> >();

        if (itemCount == 1)
        {
            if (find(candidates.begin() + startIndex, candidates.end(), target) != candidates.end())
            {
                vector < vector<int> > result(1, vector<int>(1, target));
                return result;
            }
        }
        vector < vector<int> > sub1 = getSub(candidates, target - candidates[startIndex], itemCount - 1, startIndex);
        vector < vector<int> > sub2 = getSub(candidates, target, itemCount, startIndex + 1);

        for (size_t i = 0; i < sub1.size(); i++)
        {
            sub1[i].insert(sub1[i].begin(), candidates[startIndex]);
        }
        for (size_t i = 0; i < sub2.size(); i++)
        {
            sub1.push_back(sub2[i]);
        }

        return sub1;
    }
};
