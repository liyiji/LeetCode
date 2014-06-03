/*
 * Trapping Rain Water
 * Total Accepted: 9479 Total Submissions: 33837
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */
class Solution
{
public:
    int trap(int A[], int n)
    {
        int result = 0;

        int valueOfMax = 0;
        int indexOfMaxFirst = 0;
        int indexOfMaxLast = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] > valueOfMax)
            {
                valueOfMax = A[i];
                indexOfMaxFirst = i;
                indexOfMaxLast = i;
            }
            else if (A[i] == valueOfMax)
            {
                indexOfMaxLast = i;
            }
        }

        int sumMiddle = getSubWater(A, indexOfMaxFirst, indexOfMaxLast);
        result += sumMiddle;

        while (indexOfMaxFirst > 0)
        {
            int leftMaxValue = 0;
            int leftMaxIndex = 0;
            for (int i = 0; i < indexOfMaxFirst; i++)
            {
                if (A[i] > leftMaxValue)
                {
                    leftMaxValue = A[i];
                    leftMaxIndex = i;
                }
            }
            int leftSum = getSubWater(A, leftMaxIndex, indexOfMaxFirst);
            result += leftSum;
            indexOfMaxFirst = leftMaxIndex;
        }

        while (indexOfMaxLast < n - 1)
        {
            int rightMaxValue = 0;
            int rightMaxIndex = n - 1;
            for (int i = n - 1; i > indexOfMaxLast; i--)
            {
                if (A[i] > rightMaxValue)
                {
                    rightMaxValue = A[i];
                    rightMaxIndex = i;
                }
            }
            int rightSum = getSubWater(A, indexOfMaxLast, rightMaxIndex);
            result += rightSum;
            indexOfMaxLast = rightMaxIndex;
        }

        return result;
    }

    int getSubWater(int A[], int start, int end)
    {
        if (end - start <= 1)
            return 0;

        // start and end are already two fences, AND start < end
        int tmp = min(A[start], A[end]);
        int sum = 0;
        for (int i = start + 1; i < end; i++)
        // NOT USING (int i = start; i <= end; i++) BECAUSE at start or end, there is no water
        {
            if (A[i] < tmp)
            {
                sum += tmp - A[i];
            }
        }
        return sum;
    }
};
