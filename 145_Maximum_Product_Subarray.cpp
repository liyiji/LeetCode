/*
 * Maximum Product Subarray Total Accepted: 11610 Total Submissions: 72004 My Submissions Question Solution
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

class Solution
{
public:

	int maxProduct(int A[], int n)
	{
		if (n <= 0)
			return 0;
		if (n == 1)
			return A[0];

		bool bHaveZero = false;
		vector<int> starts, ends, firstMinus, lastMinus, countMinus;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == 0)
			{
				bHaveZero = true;
				if (firstMinus.size() < starts.size())
					firstMinus.push_back(-1);
				if (lastMinus.size() < starts.size())
					lastMinus.push_back(-1);
				continue;
			}

			if (i == 0 || A[i - 1] == 0)
			{
				starts.push_back(i);
				countMinus.push_back(0);
			}
			if (i == n - 1 || A[i + 1] == 0)
				ends.push_back(i);
			if (A[i] < 0)
			{
				countMinus[countMinus.size() - 1]++;
				if (firstMinus.size() < starts.size())
					firstMinus.push_back(i);
				if (lastMinus.size() < starts.size())
					lastMinus.push_back(i);
				else
					lastMinus[lastMinus.size() - 1] = i;
			}
		}

		int result = bHaveZero ? 0 : A[0];
		for (int i = 0; i < starts.size(); i++)
		{
			if (countMinus[i] % 2 == 0)
			{
				int tmp = 1;
				for (int j = starts[i]; j <= ends[i]; j++)
					tmp *= A[j];
				if (tmp > result)
					result = tmp;
			}
			else if (countMinus[i] == 1)
			{
				int tmp1, tmp2;
				tmp1 = tmp2 = 0;
				for (int j = starts[i]; j < firstMinus[i]; j++)
				{
					if (tmp1 == 0)
						tmp1 = 1;
					tmp1 *= A[j];
				}
				for (int j = firstMinus[i] + 1; j <= ends[i]; j++)
				{
					if (tmp2 == 0)
						tmp2 = 1;
					tmp2 *= A[j];
				}
				int tmp = tmp1 > tmp2 ? tmp1 : tmp2;
				if (tmp != 0 && tmp > result)
					result = tmp;
			}
			else // (countMinus[i] % 2 == 1 && countMinus[i] != 1)
			{
				int tmp1, tmp2, tmp3;
				tmp1 = tmp2 = tmp3 = 0;
				for (int j = starts[i]; j <= firstMinus[i]; j++)
				{
					if (tmp1 == 0)
						tmp1 = 1;
					tmp1 *= A[j];
				}
				for (int j = firstMinus[i] + 1; j < lastMinus[i]; j++)
				{
					if (tmp2 == 0)
						tmp2 = 1;
					tmp2 *= A[j];
				}
				for (int j = lastMinus[i]; j <= ends[i]; j++)
				{
					if (tmp3 == 0)
						tmp3 = 1;
					tmp3 *= A[j];
				}
				int tmp = (tmp1 * tmp2) > (tmp2 * tmp3) ? (tmp1 * tmp2) : (tmp2 * tmp3);
				if (tmp != 0 && tmp > result)
					result = tmp;
			}
		}
		return result;
	}
};
