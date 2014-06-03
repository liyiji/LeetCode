/*
 * Next Permutation
 * Total Accepted: 9292 Total Submissions: 37042
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        int index = -1;
        for (int i = num.size() - 1; i >= 1; i--)
        {
            if (num[i] > num[i - 1])
            {
                index = i - 1;
                break;
            }
        }
        if (index == -1)
        {
            reverse(num.begin(), num.end());
        }
        else
        {
            int index2 = -1;
            for (int i = num.size() - 1; i > index; i--)
            {
                if (num[i] <= num[index] && num[i - 1] > num[index])
                {
                    index2 = i - 1;
                    break;
                }
            }

            if (index2 == -1)
                index2 = num.size() - 1;
            swap(num[index], num[index2]);
            reverse(num.begin() + index + 1, num.end());
        }
    }
};
