/*
 * Binary Tree Maximum Path Sum
 * Total Accepted: 12289 Total Submissions: 62706
 *
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 *
 * Return 6.
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
    int maxPathSum(TreeNode *root)
    {
        return getSub(root);
    }

    int getSub(TreeNode *p)
    {
        if (p == NULL)
            return 0;

        if (p->left == NULL && p->right == NULL)
            return p->val;

        int subLeft = getSub(p->left);
        int subRight = getSub(p->right);
        int leftToRight = maxRootToLeaf(p->left) + maxRootToLeaf(p->right) + p->val;
        return max(max(subLeft, subRight), leftToRight);
    }

    int maxRootToLeaf(TreeNode *p)
    {
        if (p == NULL)
            return 0;

        if (p->left == NULL && p->right == NULL)
            return p->val;

        int leftRootToLeaf = maxRootToLeaf(p->left);
        int rightRootToLeaf = maxRootToLeaf(p->right);
        return p->val + max(leftRootToLeaf, rightRootToLeaf);
    }
};
