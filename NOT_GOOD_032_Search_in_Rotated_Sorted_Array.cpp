/*
 * Search in Rotated Sorted Array
 * Total Accepted: 14971 Total Submissions: 53173
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 */
class Solution
{
public:
    int search(int A[], int n, int target)
    {
        for (int i = 0; i < n; i++)
        {
            if (A[i] == target)
            {
                return i;
            }
            if (i == n - 1)
            {
                return -1;
            }
        }
    }
};
