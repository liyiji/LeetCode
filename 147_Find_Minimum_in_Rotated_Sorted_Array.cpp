/*
 * Find Minimum in Rotated Sorted Array
 * Total Accepted: 14135 Total Submissions: 44557
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */
class Solution
{
public:
    int findMin(vector<int> &num)
    {
        return processSub(num, 0, num.size() - 1);
    }

    int processSub(const vector<int> &num, int start, int end)
    {
        if (end < start)
            return 0;

        switch (end - start)
        {
        case 0:
            return num[start];
        case 1:
            return min(num[start], num[end]);
        case 2:
            return min(num[start], min(num[start + 1], num[end]));
        default:
            int mid = start + (end - start) / 2;
            if (num[start] < num[end])
                return num[start];
            if (num[mid] < num[start])
                return processSub(num, start, mid);
            else
                return processSub(num, mid, end);
        }
    }
};
