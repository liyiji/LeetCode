/*
 * Unique Binary Search Trees
 * Total Accepted: 14892 Total Submissions: 41739
 *
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 */
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> num(n + 1, 0);
        for (int i = 0; i < num.size(); i++)
        {
            if (i == 0)
            {
                num[i] = 1;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    num[i] += (num[j] * num[i - j - 1]);
                }
            }
        }

        return num[n];
    }
};
