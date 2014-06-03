/*
 * Sort List
 * Total Accepted: 11818 Total Submissions: 59667
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head)
    {
        vector<ListNode *> result = sortSubList(head);
        return result[0];
    }

    vector<ListNode *> sortSubList(ListNode *head)
    {
        if (head == NULL)
        {
            vector<ListNode *> result(2, (ListNode *) (NULL));
            return result;
        }

        if (head && head->next == NULL)
        {
            vector<ListNode *> result(2, head);
            return result;
        }

        // This sub list has at least 2 nodes
        vector<ListNode *> result(2, (ListNode *) (NULL));

        ListNode *p = head;
        int midVal = p->val;

        ListNode *e = head;
        ListNode *x = NULL;
        ListNode *d = NULL;
        ListNode *ei = head;
        ListNode *xi = NULL;
        ListNode *di = NULL;
        p = p->next;
        ei->next = NULL;
        while (p)
        {
            if (p->val > midVal)
            {
                if (d == NULL)
                {
                    d = p;
                    di = p;
                }
                else
                {
                    di->next = p;
                    di = p;
                }
                p = p->next;
                di->next = NULL;
            }
            else if (p->val < midVal)
            {
                if (x == NULL)
                {
                    x = p;
                    xi = p;
                }
                else
                {
                    xi->next = p;
                    xi = p;
                }
                p = p->next;
                xi->next = NULL;
            }
            else // (p->val == midVal)
            {
                ei->next = p;
                ei = p;
                p = p->next;
                ei->next = NULL;
            }
        }

        vector<ListNode *> tmpx, tmpd;
        if (x)
        {
            tmpx = sortSubList(x);
            x = tmpx[0];
        }
        if (d)
        {
            tmpd = sortSubList(d);
            ei->next = tmpd[0];
        }

        if (x)
        {
            tmpx[1]->next = e;
            result[0] = x;
        }
        else
        {
            result[0] = e;
        }

        if (d)
        {
            result[1] = tmpd[1];
        }
        else
        {
            result[1] = ei;
        }

        return result;
    }
};
