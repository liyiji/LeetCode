/*
 * Median of Two Sorted Arrays
 * Total Accepted: 16265 Total Submissions: 94914
 *
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
class Solution
{
public:
	// Tips : The real mean of this problem is if the whole count (which means m+n) is :
	// odd  : count % 2 == 1, return array[count / 2] or array[(count - 1) / 2];
	// even : count % 2 == 0, return (double(array[(count - 1) / 2] + array[count / 2])) / 2;
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		if (m + n == 0)
			return 0;

		double result = findKth(A, m, 0, B, n, 0, (m + n) / 2);

		if ((m + n) % 2)
			return result;
		else
			return (result + findKth(A, m, 0, B, n, 0, (m + n - 1) / 2)) / 2;
	}

	int findKth(int A[], int m, int startA, int B[], int n, int startB, int k)
	{
		if (startA == m)
			return B[k + startB];
		if (startB == n)
			return A[k + startA];

		if (k == 0)
			return min(A[startA], B[startB]);

		if (k == 1)
		{
			if (m - startA == 1 && n - startB == 1)
				return max(A[startA], B[startB]);
			else if (m - startA == 1)
			{
				if (A[startA] <= B[startB])
					return B[startB];
				else
					return min(A[startA], B[startB + 1]);
			}
			else if (n - startB == 1)
			{
				if (A[startA] > B[startB])
					return A[startA];
				else
					return min(A[startA + 1], B[startB]);
			}
			else
			{
				if (A[startA] < B[startB])
					return min(A[startA + 1], B[startB]);
				if (A[startA] > B[startB])
					return min(A[startA], B[startB + 1]);
				if (A[startA] == B[startB])
					return A[startA];
			}
		}

		if (m - startA <= (k + 1) / 2)
		{
			int valueA = A[startA + (m - 1 - startA)];
			int valueB = B[startB + (k - (m - 1 - startA)) - 1];

			if (valueA > valueB)
			{
				findKth(A, m, startA, B, n, startB + (k - (m - 1 - startA)) - 1, m - 1 - startA + 1);
			}
			else if (valueA < valueB)
			{
				findKth(A, m, startA + (m - 1 - startA) + 1, B, n, startB, k - (m - 1 - startA) - 1);
			}
			else // if (valueA == valueB)
			{
				return valueA;
			}
		}
		else if (n - startB <= (k + 1) / 2)
		{
			int valueA = A[startA + (k - (n - 1 - startB)) - 1];
			int valueB = B[startB + (n - 1 - startB)];

			if (valueA > valueB)
			{
				findKth(A, m, startA, B, n, startB + (n - 1 - startB) + 1, k - (n - 1 - startB) - 1);
			}
			else if (valueA < valueB)
			{
				findKth(A, m, startA + (k - (n - 1 - startB)) - 1, B, n, startB, n - 1 - startB + 1);
			}
			else // if (valueA == valueB)
			{
				return valueA;
			}
		}
		else
		{
			int valueA = A[startA + (k + 1) / 2];
			int valueB = B[startB + (k - (k + 1) / 2)];
			if (valueA > valueB)
			{
				findKth(A, m, startA, B, n, startB + (k - (k + 1) / 2), (k + 1) / 2);
			}
			else if (valueA < valueB)
			{
				findKth(A, m, startA + (k + 1) / 2, B, n, startB, k - (k + 1) / 2);
			}
			else // if (valueA == valueB)
			{
				return valueA;
			}
		}
	}
};
