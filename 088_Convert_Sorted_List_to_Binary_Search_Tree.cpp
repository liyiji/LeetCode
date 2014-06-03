/*
 * Convert Sorted List to Binary Search Tree
 * Total Accepted: 11330 Total Submissions: 42345
 *
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
        {
            TreeNode *tn = new TreeNode(head->val);
            return tn;
        }

        if (head->next->next == NULL)
        {
            TreeNode *tn1 = new TreeNode(head->val);
            TreeNode *tn2 = new TreeNode(head->next->val);
            tn2->left = tn1;
            return tn2;
        }

        ListNode *pPre = NULL;
        ListNode *p = head;
        ListNode *q = head;
        while (q->next && q->next->next)
        {
            pPre = p;
            p = p->next;
            q = q->next->next;
        }

        ListNode *h2 = p->next;
        pPre->next = NULL;
        p->next = NULL;

        TreeNode *r = new TreeNode(p->val);
        r->left = sortedListToBST(head);
        r->right = sortedListToBST(h2);
        return r;
    }
};
