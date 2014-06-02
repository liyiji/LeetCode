/*
 * Same Tree
 * Total Accepted: 14878 Total Submissions: 35753
 * 
 * Given two binary trees, write a function to check if they are equal or not.
 * 
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((p == NULL && q == NULL) == (p != NULL && q != NULL))
        {
            return false ;
        }
        else
        {
            if (p && q)
            {
                if (p->val != q->val)
                    return false ;

                bool b = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
                return b;
            }
            else
            {
                return true ;
            }
        }
        return false ;
    }
};
