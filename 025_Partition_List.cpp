/*
 * Partition List
 * Total Accepted: 10472 Total Submissions: 39822
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *h1 = NULL;
        ListNode *h2 = NULL;
        ListNode *p = head;
        ListNode *q1 = h1;
        ListNode *q2 = h2;

        while (p)
        {
            if (p->val >= x)
            {
                if (h2 == NULL)
                {
                    h2 = p;
                    q2 = h2;
                }
                else
                {
                    q2->next = p;
                    q2 = q2->next;
                }
            }
            else // (p->val < x)
            {
                if (h1 == NULL)
                {
                    h1 = p;
                    q1 = h1;
                }
                else
                {
                    q1->next = p;
                    q1 = q1->next;
                }
            }

            p = p->next;
        }

        if (h2)
        {
            q2->next = NULL;
        }
        if (h1)
        {
            q1->next = h2;
            return h1;
        }
        else
        {
            return h2;
        }
    }
};
