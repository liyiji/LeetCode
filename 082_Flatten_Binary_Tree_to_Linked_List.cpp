/*
 * Flatten Binary Tree to Linked List
 * Total Accepted: 13271 Total Submissions: 48812
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *
 * The flattened tree should look like:
 *
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 * click to show hints.
 * Hints:
 *
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 *
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
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> vec = preorderTraversal(root);
        for (int i = 1; i < vec.size(); i++)
        {
            vec[i - 1]->right = vec[i];
            vec[i - 1]->left = NULL;
        }

        if (vec.size())
            root = vec[0];
    }

    vector<TreeNode *> preorderTraversal(TreeNode *root)
    {
        vector<TreeNode *> result;
        vector<TreeNode *> stack;
        TreeNode *p = root;

        while (true)
        {
            if (p)
            {
                result.push_back(p);
                if (p->right)
                    stack.push_back(p->right);
                if (p->left)
                    stack.push_back(p->left);
            }
            else
            {
                break;
            }

            if (stack.size())
            {
                p = stack.back();
                stack.pop_back();
            }
            else
            {
                break;
            }
        }
        return result;
    }
};
