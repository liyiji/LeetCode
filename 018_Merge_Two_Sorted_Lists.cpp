/*
 * Merge Two Sorted Lists
 * Total Accepted: 13923 Total Submissions: 43236
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *it = 0;
        bool bFirst = true;
        bool bFirstIsL1 = true;
        while (p && q)
        {
            if (p->val < q->val)
            {
                if (bFirst)
                {
                    it = p;
                    bFirst = false;
                    bFirstIsL1 = true;
                }
                else
                {
                    it->next = p;
                    it = it->next;
                }
                p = p->next;
                it->next = NULL;
            }
            else
            {
                if (bFirst)
                {
                    it = q;
                    bFirst = false;
                    bFirstIsL1 = false;
                }
                else
                {
                    it->next = q;
                    it = it->next;
                }
                q = q->next;
                it->next = NULL;
            }
        }

        if (p == NULL)
        {
            it->next = q;
        }
        if (q == NULL)
        {
            it->next = p;
        }

        if (bFirstIsL1)
            return l1;
        else
            return l2;
    }
};
