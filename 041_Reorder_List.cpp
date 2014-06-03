/*
 * Reorder List
 * Total Accepted: 11608 Total Submissions: 58568
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = head;
        if ((p && p->next && p->next->next) == false)
        {
            return;
        }

        while (q && q->next && q->next->next)
        {
            p = p->next;
            q = q->next->next;
        }

        q = p->next;
        p->next = NULL;
        q = reverse(q);

        p = head;
        ListNode *result = merge(p, q);
        head = result;
    }

    ListNode *reverse(ListNode *h)
    {
        ListNode *p = h->next;
        if (p == NULL)
            return h;

        while (p)
        {
            ListNode *q = p->next;
            p->next = h;
            if (h->next == p)
                h->next = NULL;
            h = p;
            p = q;
        }
        return h;
    }

    ListNode *merge(ListNode *p, ListNode *q)
    {
        ListNode *result = p;
        while (p && q)
        {
            if (q->next)
            {
                ListNode *t1 = p->next;
                ListNode *t2 = q->next;
                p->next = q;
                q->next = t1;
                p = t1;
                q = t2;
            }
            else
            {
                ListNode *t = p->next;
                p->next = q;
                q->next = t;
                break;
            }
        }

        return result;
    }
};
