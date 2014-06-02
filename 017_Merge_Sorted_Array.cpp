/*
 * Merge Sorted Array
 * Total Accepted: 14292 Total Submissions: 45068
 *
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */
class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        if (n == 0)
        {
            return;
        }

        if (m == 0)
        {
            for (int i = 0; i < n; i++)
            {
                A[i] = B[i];
            }
            return;
        }

        int a = m - 1;
        int b = n - 1;
        for (int i = m + n - 1; i >= 0; i--)
        {
            if (A[a] > B[b])
            {
                A[i] = A[a];
                if (a == 0)
                {
                    for (int j = 0; j < b + 1; j++)
                    {
                        A[j] = B[j];
                    }
                    break;
                }
                a--;
            }
            else
            {
                A[i] = B[b];
                if (b == 0)
                {
                    break;
                }
                b--;
            }
        }
    }
};
