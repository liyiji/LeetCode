/*
 * 4Sum
 * Total Accepted: 9743 Total Submissions: 45540
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 *     Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *     The solution set must not contain duplicate quadruplets.
 *
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 *
 */
class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector < vector<int> > result;
        if (num.size() < 4)
            return result;
        sort(num.begin(), num.end());
        int lastNum = *(num.end() - 1);
        if (lastNum * 4 < target)
            return result;
        for (size_t i1 = 0; i1 + 3 < num.size(); i1++)
        {
            if (num[i1] * 4 > target)
                break;
            if (num[i1] + lastNum * 3 < target)
                continue;
            for (size_t i2 = i1 + 1; i2 + 2 < num.size(); i2++)
            {
                if (num[i1] + num[i2] * 3 > target)
                    break;
                if (num[i1] + num[i2] + lastNum * 2 < target)
                    continue;
                for (size_t i3 = i2 + 1; i3 + 1 < num.size(); i3++)
                {
                    if (num[i1] + num[i2] + num[i3] * 2 > target)
                        break;
                    if (num[i1] + num[i2] + num[i3] + lastNum < target)
                        continue;
                    pair<vector<int>::iterator, vector<int>::iterator> bound;
                    bound = equal_range(num.begin() + i3 + 1, num.end(), target - int(num[i1]) - int(num[i2]) - int(num[i3]));
                    if (bound.first != bound.second)
                    {
                        vector<int> tmp;
                        tmp.push_back(num[i1]);
                        tmp.push_back(num[i2]);
                        tmp.push_back(num[i3]);
                        tmp.push_back(*(bound.first));
                        result.push_back(tmp);
                    }
                    while (num[i3] == num[i3 + 1])
                    {
                        i3++;
                    }
                }
                while (num[i2] == num[i2 + 1])
                {
                    i2++;
                }
            }
            while (num[i1] == num[i1 + 1])
            {
                i1++;
            }
        }
        return result;
    }
};
