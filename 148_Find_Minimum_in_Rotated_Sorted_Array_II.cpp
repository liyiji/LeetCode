/*
 * Find Minimum in Rotated Sorted Array II
 * Total Accepted: 8088 Total Submissions: 28012
 *
 *     Follow up for "Find Minimum in Rotated Sorted Array":
 *     What if duplicates are allowed?
 *
 *     Would this affect the run-time complexity? How and why?
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
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

            if (num[start] == num[end])
            {
                int tmp = num[start];
                while (start < mid && num[start] == tmp && num[start] <= num[mid])
                    start++;
                while (end > mid && num[end] == tmp && num[end] >= num[mid])
                    end--;
                return processSub(num, start, end);
            }
            else if (num[start] < num[end])
            {
                return num[start];
            }
            else // (num[start] > num[end])
            {
                if (num[mid] < num[start])
                    return processSub(num, start, mid);
                else if (num[mid] == num[start])
                    return processSub(num, mid, end);
                else // (num[mid] > num[start])
                    return processSub(num, mid, end);
            }
        }
    }
};
