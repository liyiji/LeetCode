/*
 * Minimum Depth of Binary Tree
 * Total Accepted: 13884 Total Submissions: 47863
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }

        int il = minDepth(root->left);
        int ir = minDepth(root->right);

        if (il * ir == 0)
        {
            return max(il, ir) + 1;
        }

        return min(il, ir) + 1;
    }
};
