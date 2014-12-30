/*
 * Majority Element
 * Total Accepted: 7174 Total Submissions: 22213 My Submissions Question Solution
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */
class Solution
{
public:
	int majorityElement(vector<int> &num)
	{
		int mainElement;
		int count = 0;
		for (int i = 0; i < num.size(); i++)
		{
			if (count)
			{
				if (num[i] == mainElement)
					count++;
				else
					count--;
			}
			else
			{
				mainElement = num[i];
				count++;
			}
		}
		return mainElement;
	}
};
