/*
 * Remove Duplicates from Sorted List
 * Total Accepted: 16233 Total Submissions: 47511
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
        ListNode* p = head;
        while (p && p->next)
        {
            if (p->val == p->next->val)
            {
                ListNode* q = p->next;
                p->next = q->next;
                q->next = NULL;
                delete q;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};
