/*
 * Reverse Linked List II
 * Total Accepted: 10935 Total Submissions: 42522
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode( int x) : val (x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == NULL || m == n)
            return head;

        ListNode *p = NULL;
        ListNode *pre = NULL;
        ListNode *beg = head;
        ListNode *end = NULL;
        ListNode *next = NULL;

        for (int i = 0; i < m - 1; i++)
        {
            pre = beg;
            beg = beg->next;
        }

        if (pre)
            pre->next = NULL;

        ListNode *q = beg;
        p = q->next;
        end = p;
        next = end->next;

        for (int i = 0; i < n - m; i++)
        {
            p->next = q;
            if (q->next == p)
                q->next = NULL;

            if (i < n - m - 1)
            {
                q = p;
                end = next;
                next = end->next;
                p = end;
            }
        }

        if (pre)
        {
            pre->next = end;
        }
        else
        {
            head = end;
        }

        if (next)
        {
            beg->next = next;
        }
        else
        {
            beg->next = NULL;
        }

        return head;
    }
};
