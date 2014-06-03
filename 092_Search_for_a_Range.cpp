/*
 * Search for a Range
 * Total Accepted: 11602 Total Submissions: 43184
 *
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
class Solution
{
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        vector<int> result;

        int min = 0;
        int max = n - 1;
        int mid = (min + max + 1) / 2;
        while (true)
        {
            mid = (min + max + 1) / 2;
            if (min > max)
            {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
            if (A[mid] != target)
            {
                if (A[mid] > target)
                {
                    max = mid - 1;
                }
                else if (A[mid] < target)
                {
                    min = mid + 1;
                }
            }
            else
            {
                break;
            }

        }

        int minmin = min;
        int minmax = mid;
        int minmid = (minmin + minmax + 1) / 2;
        while (true)
        {
            minmid = (minmin + minmax + 1) / 2;
            if (A[minmid] < target)
            {
                minmin = minmid + 1;
            }
            else if (A[minmid] == target)
            {
                if (minmid == 0)
                    break;
                if (A[minmid - 1] != target)
                    break;
                minmax = minmid - 1;
            }
        }

        int maxmin = mid;
        int maxmax = max;
        int maxmid = (maxmin + maxmax + 1) / 2;
        while (true)
        {
            maxmid = (maxmin + maxmax + 1) / 2;
            if (A[maxmid] > target)
            {
                maxmax = maxmid - 1;
            }
            else if (A[maxmid] == target)
            {
                if (maxmid == n - 1)
                    break;
                if (A[maxmid + 1] != target)
                    break;
                maxmin = maxmid + 1;
            }
        }

        result.push_back(minmid);
        result.push_back(maxmid);
        return result;
    }
};
