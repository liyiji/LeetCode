/*
 * Convert Sorted Array to Binary Search Tree
 * Total Accepted: 12806 Total Submissions: 40097
 *
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return createSubTree(num, 0, num.size() - 1);
    }

    TreeNode *createSubTree(vector<int> &num, int first, int last)
    {
        if (last < first)
        {
            return NULL;
        }

        int mid = (last - first + 1) / 2 + first;
        TreeNode *p = new TreeNode(num[mid]);
        if (mid - 1 >= first)
        {
            p->left = createSubTree(num, first, mid - 1);
        }
        if (mid + 1 <= last)
        {
            p->right = createSubTree(num, mid + 1, last);
        }

        return p;
    }
};
