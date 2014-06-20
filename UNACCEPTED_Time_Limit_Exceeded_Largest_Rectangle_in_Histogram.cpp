/*
 * Largest Rectangle in Histogram
 * Total Accepted: 10279 Total Submissions: 49540
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 */
class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        int result = 0;
        for (size_t i = 0; i < height.size(); i++)
        {
            int h = height[i];
            if (h * height.size() <= result)
                continue;

            int left = i;
            int right = i;
            while (left >= 0)
            {
                if (height[left] >= h)
                    left--;
                else
                    break;
            }
            left++;
            while (right < height.size())
            {
                if (height[right] >= h)
                    right++;
                else
                    break;
            }
            right--;

            int subArea = h * (right - left + 1);
            result = max(result, subArea);
        }

        return result;
    }
};
