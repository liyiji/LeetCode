/*
 * 3Sum Closest
 * Total Accepted: 11185 Total Submissions: 41774
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 */
class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        if (num.size() < 3)
            return 0;

        sort(num.begin(), num.end());
        int distance = abs(num[0] + num[1] + num[2] - target);
        int sum = num[0] + num[1] + num[2];
        bool bFinalBreak = false;
        for (int i = 0; i < num.size() - 2; i++)
        {
            for (int j = i + 1; j < num.size() - 1; j++)
            {
                int subTarget = target - num[i] - num[j];
                vector<int>::iterator up = upper_bound(num.begin() + j + 1, num.end(), subTarget);
                if (up - num.begin() - j > 1)
                {
                    int subDis = abs(*(up - 1) - subTarget);
                    if (distance > subDis)
                    {
                        distance = subDis;
                        sum = num[i] + num[j] + (*(up - 1));
                    }
                }

                int subDis = abs(*(up) - subTarget);
                if (distance > subDis)
                {
                    distance = subDis;
                    sum = num[i] + num[j] + (*(up));
                }

                if (num[i] * 3 > target)
                    bFinalBreak = true;

                if (bFinalBreak)
                    break;
            }

            if (bFinalBreak)
                break;
        }

        return sum;
    }
};
