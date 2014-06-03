/*
 * Jump Game
 * Total Accepted: 12031 Total Submissions: 44344
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 */
class Solution
{
public:
    bool canJump(int A[], int n)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] == 0)
            {
                if (i == 0)
                {
                    return false;
                }

                for (int j = i - 1; j >= 0; j--)
                {
                    if (i - j < A[j])
                    {
                        break;
                    }
                    if (j == 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
