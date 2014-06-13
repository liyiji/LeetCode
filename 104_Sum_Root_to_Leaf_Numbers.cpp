/*
 * Sum Root to Leaf Numbers
 * Total Accepted: 13616 Total Submissions: 46579
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 *
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int result = 0;
        getSub(root, result);
        return result;
    }

    void getSub(TreeNode *p, int &result)
    {
        if (p == NULL)
        {
            return;
        }
        else if (p->left == NULL && p->right == NULL)
        {
            result += p->val;
        }
        else
        {
            if (p->left)
            {
                p->left->val += (p->val * 10);
                getSub(p->left, result);
            }
            if (p->right)
            {
                p->right->val += (p->val * 10);
                getSub(p->right, result);
            }
        }
    }
};
