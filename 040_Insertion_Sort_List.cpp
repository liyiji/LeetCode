/*
 * Insertion Sort List
 * Total Accepted: 12426 Total Submissions: 50205
 *
 * Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head)
    {
        if ((head && head->next) == false)
        {
            return head;
        }

        ListNode *q = head;
        while (q && q->next)
        {
            if (q->val <= q->next->val)
            {
                q = q->next;
            }
            else if (q->next->val < head->val)
            {
                ListNode *tmp = q->next;
                q->next = tmp->next;
                tmp->next = head;
                head = tmp;
            }
            else
            {
                ListNode *p = head;
                while (p->next->val < q->next->val)
                {
                    p = p->next;
                }
                ListNode *tmp = q->next;
                q->next = tmp->next;
                tmp->next = p->next;
                p->next = tmp;
            }
        }

        return head;
    }
};
