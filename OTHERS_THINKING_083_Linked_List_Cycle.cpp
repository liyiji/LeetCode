/*
 * Linked List Cycle
 * Total Accepted: 18694 Total Submissions: 53531
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        ListNode *p = head;
        ListNode *q = head;
        while (p && q)
        {
            p = p->next;
            q = q->next;
            if (q && q->next)
            {
                q = q->next;
                if (p == q && p != NULL && q != NULL)
                    return true;
            }
            else
            {
                return false;
            }
        }
    }
};
