/*
 * Linked List Cycle II
 * Total Accepted: 13646 Total Submissions: 44831
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        if (head->next == head)
            return head;
        
        ListNode *prob = head;
        ListNode *p = head;
        ListNode *q = p;
        
        while (true)
        {
            if (q == NULL || q->next == NULL)
                return NULL;
            
            p = p->next;
            q = q->next->next;
            
            if (p == prob || q == prob)
                return prob;
            
            if (p == q)
                prob = prob->next;
        }
        
        return NULL;
    }
};
