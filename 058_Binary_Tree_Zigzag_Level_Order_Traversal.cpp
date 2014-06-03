/*
 * Binary Tree Zigzag Level Order Traversal
 * Total Accepted: 9459 Total Submissions: 36055
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<TreeNode *> queue;
        vector<vector<int> > result;

        queue.push_back(root);
        bool bReverse = false;
        while (queue.size())
        {
            vector<int> tmp = processSubLevel(queue);
            if (tmp.size())
            {
                if (bReverse)
                {
                    reverse(tmp.begin(), tmp.end());
                }
                result.push_back(tmp);
                bReverse = !bReverse;
            }
        }

        return result;
    }

    vector<int> processSubLevel(vector<TreeNode *> &queue)
    {
        int n = queue.size();
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            TreeNode *cursor = queue[i];
            if (cursor)
            {
                result.push_back(cursor->val);
                if (cursor->left)
                {
                    queue.push_back(cursor->left);
                }
                if (cursor->right)
                {
                    queue.push_back(cursor->right);
                }
            }
        }

        queue.erase(queue.begin(), queue.begin() + n);
        return result;
    }
};
