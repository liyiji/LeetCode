/*
 * Rotate List
 * Total Accepted: 9880 Total Submissions: 45319
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < k; i++)
        {
            if (q->next)
            {
                q = q->next;
            }
            else
            {
                q = head;
            }
        }

        if (q == head)
        {
            return head;
        }

        while (q->next)
        {
            p = p->next;
            q = q->next;
        }
        ListNode *newHead = p->next;

        q->next = head;
        p->next = NULL;
        return newHead;
    }
};
