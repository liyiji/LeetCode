/*
 * Binary Tree Level Order Traversal
 * Total Accepted: 13439 Total Submissions: 44011
 *
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
 * return its level order traversal as:
 *
 * [
 *   [3],
 *   [9,20],
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
 *     TreeNode( int x) : val (x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<TreeNode *> queue;
        vector<vector<int> > result;

        queue.push_back(root);
        while (queue.size())
        {
            vector<int> tmp = processSubLevel(queue);
            if (tmp.size())
                result.push_back(tmp);
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
