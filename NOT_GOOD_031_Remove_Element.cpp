/*
 * Remove Element
 * Total Accepted: 15013 Total Submissions: 46340
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
class Solution
{
public:
    int removeElement(int A[], int n, int elem)
    {
        int t = n;
        bool bWuChongFu = true;
        do
        {
            bWuChongFu = true;
            for (int i = 0; i < t; i++)
            {
                if (A[i] == elem)
                {
                    A[i] = A[t - 1];
                    t--;
                    bWuChongFu = false;
                }
            }
        } while (bWuChongFu == false);

        return t;
    }
};
