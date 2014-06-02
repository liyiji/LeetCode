/*
 * Remove Duplicates from Sorted Array
 * Total Accepted: 15894 Total Submissions: 50095
 *
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 */
class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        int uf = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] != A[uf])
            {
                uf++;
                A[uf] = A[i];
            }
        }
        return uf + 1;
    }
};
