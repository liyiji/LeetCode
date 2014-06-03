/*
 * Remove Duplicates from Sorted Array II
 * Total Accepted: 11590 Total Submissions: 38456
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */
class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n <= 2)
            return n;

        int write = 0;
        int read = 0;
        while (read < n)
        {
            int subLength = 1;
            for (int i = read + 1; i < n; i++)
            {
                if (A[i] != A[read])
                {
                    subLength = i - read;
                    break;
                }
                if (i == n - 1)
                {
                    subLength = i - read + 1;
                }
            }
            int tmp = A[read];
            A[write++] = tmp;
            if (subLength >= 2)
            {
                A[write++] = tmp;
            }
            read += subLength;
        }

        return write;
    }
};
