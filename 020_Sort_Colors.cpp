/*
 * Sort Colors
 * Total Accepted: 14112 Total Submissions: 45248
 *
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * click to show follow up.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 */
class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int i0 = 0;
        int i2 = n - 1;
        for (int i = 0; i < n; i++)
        {
            bool bSwap = false;
            do
            {
                bSwap = false;
                if (A[i] == 0)
                {
                    if (i > i0)
                    {
                        for (int j = i0; j < n; j++)
                        {
                            if (A[j] == 0)
                            {
                                i0 = j + 1;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if (i0 >= 0 && i0 < n && i0 < i)
                        {
                            swap(A[i], A[i0]);
                            bSwap = true;
                        }
                    }
                }
                if (A[i] == 2)
                {
                    if (i < i2)
                    {
                        for (int j = i2; j >= 0; j--)
                        {
                            if (A[j] == 2)
                            {
                                i2 = j - 1;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if (i2 >= 0 && i2 < n && i2 > i)
                        {
                            swap(A[i], A[i2]);
                            bSwap = true;
                        }
                    }
                }
            } while (A[i] != 1 && bSwap);
        }
    }
};
