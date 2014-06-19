/*
 * 3Sum Closest
 * Total Accepted: 10825 Total Submissions: 40503
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
        int distance = -1;
        int sum = 0;
        for (int i = 0; i < num.size() - 2; i++)
        {
            for (int j = i + 1; j < num.size() - 1; j++)
            {
                for (int k = j + 1; k < num.size(); k++)
                {
                    int newSum = num[i] + num[j] + num[k];
                    int newDis = abs(target - newSum);
                    if (distance < 0)
                    {
                        distance = newDis;
                        sum = newSum;
                    }
                    else
                    {
                        if (newDis < distance)
                        {
                            distance = newDis;
                            sum = newSum;
                        }
                    }

                    if (num[i] + num[j] + num[k] > target)
                        break;
                }

                if (num[i] + num[j] * 2 > target)
                    break;
            }

            if (num[i] * 3 > target)
                break;
        }

        return sum;
    }
};
