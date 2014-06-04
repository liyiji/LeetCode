/*
 * Add Two Numbers
 * Total Accepted: 14245 Total Submissions: 63176
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *pPre = NULL;

        while (p1 && p2)
        {
            p1->val += p2->val;
            if (p1->val > 9)
            {
                p1->val -= 10;
                if (p1->next)
                {
                    p1->next->val += 1;
                }
                else
                {
                    if (p2->next)
                    {
                        p1->next = p2->next;
                        p1->next->val++;
                        while (p1->next)
                        {
                            if (p1->val > 9)
                            {
                                p1->val -= 10;
                                p1->next->val++;
                            }
                            p1 = p1->next;
                        }
                        if (p1->val > 9)
                        {
                            p1->val -= 10;
                            ListNode *tmp = new ListNode(1);
                            p1->next = tmp;
                        }
                        return l1;
                    }
                    else
                    {
                        ListNode *tmp = new ListNode(1);
                        p1->next = tmp;
                        return l1;
                    }
                }
            }
            pPre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p2 == NULL)
        {
            if (p1)
            {
                while (p1->next)
                {
                    if (p1->val > 9)
                    {
                        p1->val -= 10;
                        p1->next->val++;
                    }
                    p1 = p1->next;
                }
                if (p1->val > 9)
                {
                    p1->val -= 10;
                    ListNode *tmp = new ListNode(1);
                    p1->next = tmp;
                }
            }
            return l1;
        }
        else
        {
            pPre->next = p2;
            return l1;
        }
    }
};
