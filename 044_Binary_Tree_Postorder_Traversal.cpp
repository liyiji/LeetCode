/*
 * Binary Tree Postorder Traversal
 * Total Accepted: 17833 Total Submissions: 58112
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        vector<TreeNode *> stack;
        TreeNode *p = root;

        while (true)
        {
            if (p)
            {
                TreeNode *l = p->left;
                TreeNode *r = p->right;
                if (r == NULL && l == NULL)
                {
                    result.push_back(p->val);
                }
                else
                {
                    stack.push_back(p);
                    p->left = NULL;
                    p->right = NULL;
                    if (r)
                        stack.push_back(r);
                    if (l)
                        stack.push_back(l);
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
