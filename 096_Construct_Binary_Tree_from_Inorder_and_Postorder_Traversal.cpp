/*
 * Construct Binary Tree from Inorder and Postorder Traversal
 * Total Accepted: 8953 Total Submissions: 34352
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildSubTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *buildSubTree(const vector<int> &vin, const vector<int> &vpost, int inStart, int inEnd, int postStart, int postEnd)
    {
        int wholeLength = postEnd - postStart + 1;

        if (wholeLength == 0)
            return NULL;

        if (wholeLength == 1)
        {
            TreeNode *tmp = new TreeNode(vpost[postEnd]);
            return tmp;
        }

        TreeNode *root = new TreeNode(vpost[postEnd]);
        int index = getIndex(vin, vpost[postEnd]);
        int leftLength = index - inStart;
        int rightLength = inEnd - index;

        if (leftLength)
        {
            root->left = buildSubTree(vin, vpost, inStart, inStart + leftLength - 1, postStart, postStart + leftLength - 1);
        }

        if (rightLength)
        {
            root->right = buildSubTree(vin, vpost, index + 1, inEnd, postStart + leftLength, postEnd - 1);
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
