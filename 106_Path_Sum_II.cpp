/*
 * Path Sum II
 * Total Accepted: 12903 Total Submissions: 47466
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
 *
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 *
 * return
 *
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 *
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
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        vector < vector<int> > result = getSub(root, sum);
        for (size_t i = 0; i < result.size(); i++)
        {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }

    vector<vector<int> > getSub(TreeNode *p, int target)
    {
        vector < vector<int> > result;
        if (p == NULL)
            return result;

        if (p->left == NULL && p->right == NULL)
        {
            if (p->val == target)
            {
                vector<int> tmp;
                tmp.push_back(p->val);
                result.push_back(tmp);
            }
            return result;
        }
        else
        {
            if (p->left)
            {
                vector < vector<int> > subResult = getSub(p->left, target - p->val);
                for (size_t i = 0; i < subResult.size(); i++)
                {
                    vector<int> tmp = subResult[i];
                    tmp.push_back(p->val);
                    result.push_back(tmp);
                }
            }

            if (p->right)
            {
                vector < vector<int> > subResult = getSub(p->right, target - p->val);
                for (size_t i = 0; i < subResult.size(); i++)
                {
                    vector<int> tmp = subResult[i];
                    tmp.push_back(p->val);
                    result.push_back(tmp);
                }
            }

            return result;
        }
    }
};
