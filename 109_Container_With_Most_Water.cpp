/*
 * Container With Most Water
 * Total Accepted: 10693 Total Submissions: 35061
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = getSub(height, 0, height.size() - 1);
    }

    int getSub(vector<int> &height, int start, int end)
    {
        if (start >= end)
            return 0;

        if (end - start == 1)
        {
            return min(height[start], height[end]);
        }

        int mid = (start + end) / 2;
        if (end - start == 2)
        {
            return max(max(min(height[start], height[mid]), min(height[mid], height[end])), min(height[start], height[end]) * 2);
        }

        // (end - start > 2) is below
        int left = getSub(height, start, mid);
        int right = getSub(height, mid, end);
        int leftAndRight = 0;
        int il = start;
        int ir = end;
        vector<int> leftIndices;
        vector<int> rightIndices;
        for (size_t i = start; i < mid; i++)
        {
            if (i == start)
            {
                leftIndices.push_back(i);
            }
            else
            {
                if (height[i] > height[i - 1])
                    leftIndices.push_back(i);
            }
        }
        for (size_t i = end; i > mid; i--)
        {
            if (i == end)
            {
                rightIndices.push_back(i);
            }
            else
            {
                if (height[i] > height[i + 1])
                    rightIndices.push_back(i);
            }
        }

        for (size_t i = 0; i < leftIndices.size(); i++)
        {
            for (size_t j = 0; j < rightIndices.size(); j++)
            {
                if (height[leftIndices[i]] <= height[rightIndices[j]])
                {
                    int realWidth = rightIndices[j] - leftIndices[i];
                    int realHeight = height[leftIndices[i]];
                    leftAndRight = max(leftAndRight, realHeight * realWidth);
                    break;
                }
                else
                {
                    int realWidth = rightIndices[j] - leftIndices[i];
                    int realHeight = height[rightIndices[j]];
                    leftAndRight = max(leftAndRight, realHeight * realWidth);
                }
            }
        }

        return max(max(left, right), leftAndRight);
    }
};
