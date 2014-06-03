/*
 * First Missing Positive
 * Total Accepted: 10284 Total Submissions: 47027
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 */
class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        vector<bool> marks(n, false);
        for (int i = 0; i < n; i++)
        {
            if (A[i] > 0 && A[i] <= n)
            {
                marks[A[i] - 1] = true;
            }
        }

        int it;
        for (it = 0; it < n; it++)
        {
            if (marks[it] == false)
            {
                return it + 1;
            }
        }
        return it + 1;
    }
};
