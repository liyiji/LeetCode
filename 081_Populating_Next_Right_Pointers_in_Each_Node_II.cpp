/*
 * Populating Next Right Pointers in Each Node II
 * Total Accepted: 10588 Total Submissions: 35778
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 *     You may only use constant extra space.
 *
 * For example,
 * Given the following binary tree,
 *
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 *
 * After calling your function, the tree should look like:
 *
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
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
                }
                if (vec[i]->right)
                {
                    vec.push_back(vec[i]->right);
                }
            }
            if (vec[n - 1]->left)
            {
                vec.push_back(vec[n - 1]->left);
            }
            if (vec[n - 1]->right)
            {
                vec.push_back(vec[n - 1]->right);
            }
            vec.erase(vec.begin(), vec.begin() + n);
        }
    }
};
