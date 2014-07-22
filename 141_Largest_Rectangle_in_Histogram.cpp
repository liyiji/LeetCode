/*
 * Largest Rectangle in Histogram
 * Total Accepted: 11933 Total Submissions: 57238
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
        if (height.empty())
            return 0;
        if (height.size() == 1)
            return height[0];

        int result = processSub(height, 0, height.size() - 1);
        return result;
    }

    int processSub(const vector<int> &height, int start, int end)
    {
        if (end < start || end >= height.size() || start < 0)
            return 0;

        int length = end - start + 1;
        if (length == 1)
        {
            return height[start];
        }
        else if (length == 2)
        {
            return max(max(height[start], height[end]), min(height[start], height[end]) * 2);
        }
        else
        {
            if ((end - start) % 2)
            {
                int maxLR = max(processSub(height, start, (end + start - 1) / 2), processSub(height, (end + start + 1) / 2, end));
                return max(maxLR, processMid(height, start, end, (end + start - 1) / 2, (end + start + 1) / 2));
            }
            else
            {
                int maxLR = max(processSub(height, start, (start + end) / 2), processSub(height, (start + end) / 2, end));
                return max(maxLR, processMid(height, start, end, (start + end) / 2 - 1, (start + end) / 2 + 1));
            }
        }
    }

    int processMid(const vector<int> &height, int start, int end, int from, int to)
    {
        if (end < start || end >= height.size() || start < 0 || to < from || to > end || from < start)
            return 0;

        int curHeight = height[from];
        int result = 0;
        for (int i = from; i <= to; i++)
        {
            curHeight = min(curHeight, height[i]);
        }

        while (to < end && height[to + 1] >= curHeight)
            to++;
        while (from > start && height[from - 1] >= curHeight)
            from--;
        result = curHeight * (to - from + 1);

        int subResult = 0;
        while (true)
        {
            if (from == start && to == end)
            {
                result = max(result, curHeight * (to - from + 1));
                break;
            }
            else if (from == start || to == end)
            {
                if (from == start)
                {
                    curHeight = height[to + 1];
                    while (to < end && height[to + 1] >= curHeight)
                        to++;

                    result = max(result, curHeight * (to - from + 1));
                }
                else if (to == end)
                {
                    curHeight = height[from - 1];
                    while (from > start && height[from - 1] >= curHeight)
                        from--;

                    result = max(result, curHeight * (to - from + 1));
                }
            }
            else
            {
                if (height[from - 1] < height[to + 1])
                {
                    curHeight = height[to + 1];
                    while (to < end && height[to + 1] >= curHeight)
                        to++;
                }
                else if (height[from - 1] < height[to + 1])
                {
                    curHeight = height[from - 1];
                    while (from > start && height[from - 1] >= curHeight)
                        from--;
                }
                else // equal
                {
                    curHeight = height[from - 1];
                    while (to < end && height[to + 1] >= curHeight)
                        to++;
                    while (from > start && height[from - 1] >= curHeight)
                        from--;
                }
                result = max(result, curHeight * (to - from + 1));
            }
        }

        return result;
    }
};
