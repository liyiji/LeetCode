/*
 * Construct Binary Tree from Preorder and Inorder Traversal
 * Total Accepted: 9077 Total Submissions: 35317
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildSubTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *buildSubTree(const vector<int> &vpre, const vector<int> &vin, int preStart, int preEnd, int inStart, int inEnd)
    {
        int wholeLength = preEnd - preStart + 1;

        if (wholeLength == 0)
            return NULL;

        if (wholeLength == 1)
        {
            TreeNode *tmp = new TreeNode(vpre[preStart]);
            return tmp;
        }

        TreeNode *root = new TreeNode(vpre[preStart]);
        int index = getIndex(vin, vpre[preStart]);
        int leftLength = index - inStart;
        int rightLength = inEnd - index;

        if (leftLength)
        {
            root->left = buildSubTree(vpre, vin, preStart + 1, preStart + leftLength, inStart, inStart + leftLength - 1);
        }

        if (rightLength)
        {
            root->right = buildSubTree(vpre, vin, preStart + leftLength + 1, preEnd, index + 1, inEnd);
        }

        return root;
    }

    int getIndex(const vector<int> &vec, int target)
    // Search for index of target in vector
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == target)
                return i;
        }
        return -1;
    }
};
