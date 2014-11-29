/*
 * Intersection of Two Linked Lists
 * Total Accepted: 1637 Total Submissions: 5737
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗
 * B:     b1 → b2 → b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 *
 *     If the two linked lists have no intersection at all, return null.
 *     The linked lists must retain their original structure after the function returns.
 *     You may assume there are no cycles anywhere in the entire linked structure.
 *     Your code should preferably run in O(n) time and use only O(1) memory.
 *
 * Credits:
 * Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int countA = 0;
        int countB = 0;
        ListNode *tmpA, *tmpB;
        tmpA = headA;
        tmpB = headB;
        while (tmpA)
        {
            tmpA = tmpA->next;
            countA++;
        }
        while (tmpB)
        {
            tmpB = tmpB->next;
            countB++;
        }
        tmpA = headA;
        tmpB = headB;
        if (countA > countB)
        {
            for (int i = 0; i < countA - countB; i++)
            {
                tmpA = tmpA->next;
            }
        }
        else if (countA < countB)
        {
            for (int i = 0; i < countB - countA; i++)
            {
                tmpB = tmpB->next;
            }
        }
        ListNode *result = NULL;
        int count = min(countA, countB);
        while (count)
        {
            if (tmpA->val == tmpB->val)
            {
                if (result == NULL)
                    result = tmpA;
            }
            else
            {
                result = NULL;
            }
            count--;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return result;
    }
};
