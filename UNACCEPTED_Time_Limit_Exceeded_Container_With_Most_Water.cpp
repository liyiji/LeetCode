/*
 * Container With Most Water
 * Total Accepted: 10446 Total Submissions: 34312
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
        int n = height.size();
        int finalMax = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (height[i] == 0)
                continue;
            for (int j = n - 1; j > (finalMax / height[i]) + i; j--)
            {
                if (height[j] == 0)
                    continue;
                if (j <= (finalMax / height[j]) + i)
                    continue;
//                if (height[j] >= height[i])
//                {
//                    int curMax = height[i] * (j - i);
//                    if (curMax > finalMax)
//                    {
//                        finalMax = curMax;
//                        break;
//                    }
//                }

                int cur = min(height[i], height[j]) * (j - i);
                if (cur > finalMax)
                    finalMax = cur;
            }
        }
        return finalMax;
    }
};
