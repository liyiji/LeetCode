/*
 * Remove Duplicates from Sorted List II
 * Total Accepted: 11348 Total Submissions: 46409
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *pPre = NULL;

        while (true)
        {
            if (p->val == q->val)
            {
                while (true)
                {
                    q = q->next;
                    if (q == NULL || (q->val != p->val))
                        break;
                }

                if (q)
                {
                    if (pPre)
                    {
                        pPre->next = q;
                        p = q;
                        q = p->next;
                    }
                    else
                    {
                        head = q;
                        p = head;
                        q = p->next;
                    }
                    if (q == NULL)
                        return head;
                }
                else
                {
                    if (pPre)
                    {
                        pPre->next = NULL;
                        return head;
                    }
                    else
                        return NULL;
                }
            }
            else
            {
                pPre = p;
                p = p->next;
                q = p->next;
                if (q == NULL)
                    return head;
            }
        }
    }
};
