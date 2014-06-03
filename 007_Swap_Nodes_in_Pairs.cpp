/*
 * Swap Nodes in Pairs
 * Total Accepted: 13536 Total Submissions: 42472
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode* p = head;
        ListNode* bak = 0;
        bool b = true;
        while (p && p->next)
        {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = p;
            if (bak)
                bak->next = q;

            if (b)
            {
                head = q;
                b = false;
            }
            bak = p;
            p = p->next;
        }
        return head;
    }
};
