/*
 * Merge k Sorted Lists
 * Total Accepted: 11181 Total Submissions: 47869
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        while (true)
        {
            for (int i = 0; i < lists.size() / 2; i++)
            {
                merge(lists[i * 2], lists[i * 2 + 1]);
                lists[i * 2 + 1] = NULL;
            }

            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] == NULL)
                {
                    for (int j = i; j < lists.size(); j++)
                    {
                        if (lists[j] != NULL)
                        {
                            swap(lists[i], lists[j]);
                            break;
                        }
                        if (j == lists.size() - 1)
                        {
                            lists.resize(i);
                        }
                    }
                }
            }

            if (lists.size() <= 1)
            {
                break;
            }
        }

        if (lists.size())
            return lists[0];
        else
            return NULL;
    }

    void merge(ListNode *&l1, ListNode *&l2)
    {
        if (l2 == NULL)
            return;
        if (l1 == NULL)
        {
            swap(l1, l2);
            return;
        }

        if (l1->val > l2->val)
        {
            swap(l1, l2);
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 && p2)
        {
            if (p2->val >= p1->val)
            {
                if (p1->next == NULL)
                {
                    p1->next = p2;
                    break;
                }
                else
                {
                    if (p2->val < p1->next->val)
                    {
                        ListNode *p1Next = p1->next;
                        ListNode *p2Next = p2->next;
                        p1->next = p2;
                        p2->next = p1Next;
                        p1 = p2;
                        p2 = p2Next;
                    }
                    else
                    {
                        p1 = p1->next;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
};
