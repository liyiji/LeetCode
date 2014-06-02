/*
 * Binary Tree Inorder Traversal
 * Total Accepted: 18579 Total Submissions: 53224
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        vector<TreeNode *> stack;
        TreeNode *p = root;

        while (true)
        {
            if (p)
            {
                if (p->right == NULL && p->left == NULL)
                {
                    result.push_back(p->val);
                }
                else
                {
                    if (p->right)
                        stack.push_back(p->right);
                    stack.push_back(p);
                    if (p->left)
                        stack.push_back(p->left);
                    p->left = NULL;
                    p->right = NULL;
                }
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
