/*
 * Jump Game II
 * Total Accepted: 10099 Total Submissions: 42256
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
class Solution
{
public:
    int jump(int A[], int n)
    {
        if (n == 1)
        {
            return 0;
        }
        vector<int> minStep(n - 1, -1);
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] == 0)
            {
                minStep[i] = -2;
                continue;
            }
            if (i + A[i] >= n - 1)
            {
                minStep[i] = 1;
                continue;
            }
            for (int j = A[i] + i; j >= i + 1; j--)
            {
                if (minStep[j] == -2)
                    continue;
                if (minStep[i] == -1)
                {
                    minStep[i] = minStep[j] + 1;
                }
                else
                {
                    if (minStep[j] + 1 < minStep[i])
                        minStep[i] = minStep[j] + 1;
                }
                if (minStep[i] == 2)
                    break;
            }
            if (minStep[i] == -1)
                minStep[i] = -2;
        }

        return minStep[0];
    }
};
