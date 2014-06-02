/*
 * Binary Tree Preorder Traversal
 * Total Accepted: 19730 Total Submissions: 56512
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 * return [1,2,3].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        vector<TreeNode *> stack;
        TreeNode *p = root;

        while (true)
        {
            if (p)
            {
                result.push_back(p->val);
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
