/*
 * Reverse Nodes in k-Group
 * Total Accepted: 8683 Total Submissions: 35276
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k <= 1)
            return head;

        ListNode *p = head;
        ListNode *q = p;
        bool b = false;
        for (int i = 0; i < k - 1; i++)
        {
            q = q->next;
            if (q == NULL)
            {
                b = true;
                break;
            }
        }
        if (b)
            return head;

        subReverse(NULL, p, q, q->next);
        head = q;

        while (true)
        {
            ListNode *pPre = p;
            p = p->next;
            q = p;
            if (p == NULL)
                break;

            b = false;
            for (int i = 0; i < k - 1; i++)
            {
                q = q->next;
                if (q == NULL)
                {
                    b = true;
                    break;
                }
            }
            if (b)
                break;

            subReverse(pPre, p, q, q->next);
        }

        return head;
    }

    void subReverse(ListNode *hPre, ListNode *h, ListNode *t, ListNode *tNext)
    {
        if (h == t)
        {
            return;
        }

        if (hPre)
            hPre->next = NULL;
        if (tNext)
            t->next = NULL;

        if (h->next == t)
        {
            h->next = NULL;
            t->next = h;
        }
        else
        {
            ListNode *p = h;
            ListNode *q = p->next;
            ListNode *r = q->next;
            h->next = NULL;
            while (r)
            {
                q->next = p;
                p = q;
                q = r;
                r = r->next;
            }
            q->next = p;
        }

        if (hPre)
            hPre->next = t;
        if (tNext)
            h->next = tNext;
    }
};
