/*
 * Symmetric Tree
 * Total Accepted: 15329 Total Submissions: 48332
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *
 * But the following is not:
 *
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == 0)
        {
            return true;
        }
        if (isSym(root->left, root->right))
        {
            return true;
        }
    }

    bool isSym(TreeNode *left, TreeNode *right)
    {
        if (left == 0 && right == 0)
        {
            return true;
        }
        if ((left == 0 && right != 0) || (left != 0 && right == 0))
        {
            return false;
        }
        if (left != 0 && right != 0)
        {
            bool b1 = isSym(left->left, right->right);
            bool b2 = isSym(left->right, right->left);
            bool b3 = (left->val == right->val);
            return b3 && b1 && b2;
        }
    }
};
