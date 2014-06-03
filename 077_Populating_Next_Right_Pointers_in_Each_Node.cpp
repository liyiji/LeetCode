/*
 * Populating Next Right Pointers in Each Node
 * Total Accepted: 14964 Total Submissions: 43191
 *
 * Given a binary tree
 *
 *     struct TreeLinkNode {
 *       TreeLinkNode *left;
 *       TreeLinkNode *right;
 *       TreeLinkNode *next;
 *     }
 *
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 *     You may only use constant extra space.
 *     You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *
 * For example,
 * Given the following perfect binary tree,
 *
 *          1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 *
 * After calling your function, the tree should look like:
 *
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
 *
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (root)
        {
            vector<TreeLinkNode *> vec;
            vec.push_back(root);
            connectSub(vec);
        }
    }

    void connectSub(vector<TreeLinkNode *> vec)
    {
        while (vec.size())
        {
            int n = vec.size();
            for (int i = 0; i < n - 1; i++)
            {
                vec[i]->next = vec[i + 1];
                if (vec[i]->left)
                {
                    vec.push_back(vec[i]->left);
                    vec.push_back(vec[i]->right);
                }
            }
            if (vec[n - 1]->left)
            {
                vec.push_back(vec[n - 1]->left);
                vec.push_back(vec[n - 1]->right);
            }
            vec.erase(vec.begin(), vec.begin() + n);
        }
    }
};
