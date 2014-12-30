/*
 * Find Peak Element
 * Total Accepted: 7738 Total Submissions: 24363
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 * click to show spoilers.
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */
class Solution
{
public:
	int findPeakElement(const vector<int> &num)
	{
		if (num.size() < 2)
			return 0;

		int step = 1;
		int startIndex = 0;
		int endIndex = num.size() - 1;
		int cur = startIndex;
		bool bPlusOrMinus = true;
		int dis = endIndex - startIndex;
		int newDis = -1;

		while (true)
		{
			if (newDis != -1)
			{
				if (newDis == dis)
					break;
				else
					dis = newDis;
			}
			if (bPlusOrMinus)
			{
				while (true)
				{
					if (cur + step <= endIndex)
					{
						if (num[cur + step] < num[cur])
						{
							endIndex = cur + step;
							if (step > 1)
								startIndex = cur - (step / 2);
							step = 1;
							bPlusOrMinus = !bPlusOrMinus;
							break;
						}
						else
						{
							cur += step;
							step *= 2;
						}
					}
					else
					{
						if (num[endIndex] < num[cur])
						{
							if (step > 1)
								startIndex = cur - (step / 2);
							step = 1;
							bPlusOrMinus = !bPlusOrMinus;
							break;
						}
						else
						{
							cur = endIndex;
							step = 1;
							bPlusOrMinus = !bPlusOrMinus;
							break;
						}
					}
				}
			}
			else
			{
				while (true)
				{
					if (cur - step >= startIndex)
					{
						if (num[cur - step] < num[cur])
						{
							startIndex = cur - step;
							if (step > 1)
								endIndex = cur + (step / 2);
							step = 1;
							bPlusOrMinus = !bPlusOrMinus;
							break;
						}
						else
						{
							cur -= step;
							step *= 2;
						}
					}
					else
					{
						if (num[startIndex] < num[cur])
						{
							if (step > 1)
								endIndex = cur + (step / 2);
							step = 1;
							bPlusOrMinus = !bPlusOrMinus;
							break;
						}
						else
						{
							cur = startIndex;
							step = 1;
							bPlusOrMinus = !bPlusOrMinus;
							break;
						}
					}
				}
			}
			newDis = endIndex - startIndex;
		}
		for (int i = startIndex; i < endIndex; i++)
		{
			if (num[i] > num[i + 1])
				return i;
		}
		return endIndex;
	}
};
