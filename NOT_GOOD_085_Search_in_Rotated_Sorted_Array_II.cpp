/*
 * Search in Rotated Sorted Array II
 * Total Accepted: 9763 Total Submissions: 32412
 *
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 */
class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        for (int i = 0; i < n; i++)
        {
            if (A[i] == target)
            {
                return true;
            }
            if (i == n - 1)
            {
                return false;
            }
        }
    }
};
