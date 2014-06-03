/*
 * Unique Binary Search Trees II
 * Total Accepted: 8149 Total Submissions: 30584
 *
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 *
 * OJ's Binary Tree Serialization:
 *
 * The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 *
 * Here's an example:
 *
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 *
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode( int x) : val (x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<int> nums(n, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                nums[i] = 1;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    nums[i] += (nums[j] * nums[i - j - 1]);
                }
            }
        }

        return generateSubTree(1, n, nums);
    }

    vector<TreeNode *> generateSubTree(int min, int max, const vector<int> &nums)
    {
        int n = max - min + 1;
        vector<TreeNode *> result;

        if (n <= 0)
        {
            TreeNode *t = NULL;
            result.push_back(t);
        }
        if (n == 1) // min == max
        {
            result.push_back(new TreeNode(min));
        }
        if (n == 2)
        {
            {
                TreeNode *small = new TreeNode(min);
                TreeNode *big = new TreeNode(max);
                small->right = big;
                result.push_back(small);
            }
            {
                TreeNode *small = new TreeNode(min);
                TreeNode *big = new TreeNode(max);
                big->left = small;
                result.push_back(big);
            }
        }
        if (n > 2)
        {
            for (int i = min; i <= max; i++)
            {
                if (i == min)
                {
                    vector<TreeNode *> rightChilds = generateSubTree(min + 1, max, nums);
                    for (int j = 0; j < rightChilds.size(); j++)
                    {
                        result.push_back(new TreeNode(min));
                        result[result.size() - 1]->right = rightChilds[j];
                    }
                }
                else if (i == max)
                {
                    vector<TreeNode *> leftChilds = generateSubTree(min, max - 1, nums);
                    for (int j = 0; j < leftChilds.size(); j++)
                    {
                        result.push_back(new TreeNode(max));
                        result[result.size() - 1]->left = leftChilds[j];
                    }
                }
                else
                {
                    vector<TreeNode *> leftChilds = generateSubTree(min, i - 1, nums);
                    vector<TreeNode *> rightChilds = generateSubTree(i + 1, max, nums);
                    for (int j = 0; j < leftChilds.size(); j++)
                    {
                        for (int k = 0; k < rightChilds.size(); k++)
                        {
                            result.push_back(new TreeNode(i));
                            result[result.size() - 1]->left = leftChilds[j];
                            result[result.size() - 1]->right = rightChilds[k];
                        }
                    }
                }
            }
        }

        return result;
    }
};
