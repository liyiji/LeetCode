/*
 * Recover Binary Search Tree
 * Total Accepted: 11487 Total Submissions: 49712
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode *root)
    {
        TreeNode *pMin, *pMax;
        processSub(root, pMin, pMax);
    }

    void processSub(TreeNode *p, TreeNode *&leftMaxNode, TreeNode *&rightMinNode)
    {
        leftMaxNode = getMaxNodeOfCurTree(p->left);
        rightMinNode = getMinNodeOfCurTree(p->right);

        if (leftMaxNode == NULL)
        {
            if (rightMinNode == NULL)
            {
                return;
            }
            else
            {
                if (rightMinNode->val < p->val)
                {
                    swap(p->val, rightMinNode->val);
                    return;
                }
                else
                {
                    processSub(p->right, leftMaxNode, rightMinNode);
                }
            }
        }
        else
        {
            if (rightMinNode == NULL)
            {
                if (leftMaxNode->val > p->val)
                {
                    swap(p->val, leftMaxNode->val);
                    return;
                }
                else
                {
                    processSub(p->left, leftMaxNode, rightMinNode);
                }
            }
            else
            {
                int a = leftMaxNode->val;
                int b = p->val;
                int c = rightMinNode->val;
                if (a < b)
                {
                    if (b < c)
                    {
                        processSub(p->left, leftMaxNode, rightMinNode);
                        processSub(p->right, leftMaxNode, rightMinNode);
                        return;
                    }
                    else if (c < a)
                    {
                        // impossible
                    }
                    else // a < c < b
                    {
                        swap(p->val, rightMinNode->val);
                        return;
                    }
                }
                else // a > b
                {
                    if (c > a)
                    {
                        swap(p->val, leftMaxNode->val);
                        return;
                    }
                    else if (c < b)
                    {
                        swap(leftMaxNode->val, rightMinNode->val);
                        return;
                    }
                    else // b < c < a
                    {
                        // impossible
                    }
                }
            }
        }
    }

    TreeNode *getMinNodeOfCurTree(TreeNode *p)
    {
        if (p == NULL)
        {
            return NULL;
        }
        else
        {
            if (p->left == NULL)
            {
                if (p->right == NULL)
                {
                    return p;
                }
                else
                {
                    TreeNode *tmp = getMinNodeOfCurTree(p->right);
                    if (p->val < tmp->val)
                        return p;
                    else
                        return tmp;
                }
            }
            else
            {
                if (p->right == NULL)
                {
                    TreeNode *tmp = getMinNodeOfCurTree(p->left);
                    if (p->val < tmp->val)
                        return p;
                    else
                        return tmp;
                }
                else
                {
                    TreeNode *tmp1 = getMinNodeOfCurTree(p->left);
                    TreeNode *tmp2 = getMinNodeOfCurTree(p->right);
                    if (tmp1->val < tmp2->val)
                    {
                        if (p->val < tmp1->val)
                            return p;
                        else
                            return tmp1;
                    }
                    else
                    {
                        if (p->val < tmp2->val)
                            return p;
                        else
                            return tmp2;
                    }
                }
            }
        }
    }

    TreeNode *getMaxNodeOfCurTree(TreeNode *p)
    {
        if (p == NULL)
        {
            return NULL;
        }
        else
        {
            if (p->left == NULL)
            {
                if (p->right == NULL)
                {
                    return p;
                }
                else
                {
                    TreeNode *tmp = getMaxNodeOfCurTree(p->right);
                    if (p->val > tmp->val)
                        return p;
                    else
                        return tmp;
                }
            }
            else
            {
                if (p->right == NULL)
                {
                    TreeNode *tmp = getMaxNodeOfCurTree(p->left);
                    if (p->val > tmp->val)
                        return p;
                    else
                        return tmp;
                }
                else
                {
                    TreeNode *tmp1 = getMaxNodeOfCurTree(p->left);
                    TreeNode *tmp2 = getMaxNodeOfCurTree(p->right);
                    if (tmp1->val > tmp2->val)
                    {
                        if (p->val > tmp1->val)
                            return p;
                        else
                            return tmp1;
                    }
                    else
                    {
                        if (p->val > tmp2->val)
                            return p;
                        else
                            return tmp2;
                    }
                }
            }
        }
    }
};
