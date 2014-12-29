/*
 *Compare Version Numbers
 *Total Accepted: 4191 Total Submissions: 28994
 *
 *Compare two version numbers version1 and version1.
 *If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 *You may assume that the version strings are non-empty and contain only digits and the . character.
 *The . character does not represent a decimal point and is used to separate number sequences.
 *For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 *Here is an example of version numbers ordering:
 *
 *0.1 < 1.1 < 1.2 < 13.37
 *
 *Credits:
 *Special thanks to @ts for adding this problem and creating all test cases.
 */
class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		vector<int> v1, v2;
		size_t cursor = 0;
		while (true)
		{
			size_t p = version1.find(".", cursor);
			if (p == string::npos)
			{
				v1.push_back(stoi(version1.substr(cursor)));
				break;
			}
			else
			{
				v1.push_back(stoi(version1.substr(cursor, p)));
				cursor = p + 1;
			}
		}
		cursor = 0;
		while (true)
		{
			size_t p = version2.find(".", cursor);
			if (p == string::npos)
			{
				v2.push_back(stoi(version2.substr(cursor)));
				break;
			}
			else
			{
				v2.push_back(stoi(version2.substr(cursor, p)));
				cursor = p + 1;
			}
		}
		size_t i;
		for (i = 0; i < min(v1.size(), v2.size()); i++)
		{
			if (v1[i] > v2[i])
				return 1;
			else if (v1[i] < v2[i])
				return -1;
		}
		if (v1.size() > v2.size())
		{
			for (size_t j = v2.size(); j < v1.size(); j++)
			{
				if (v1[j] != 0)
					return 1;
			}
			return 0;
		}
		else if (v1.size() < v2.size())
		{
			for (size_t j = v1.size(); j < v2.size(); j++)
			{
				if (v2[j] != 0)
					return -1;
			}
			return 0;
		}
		else
			return 0;
	}
};
