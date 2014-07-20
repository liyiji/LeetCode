/*
 * Copy List with Random Pointer
 * Total Accepted: 14362 Total Submissions: 63168
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == NULL)
            return NULL;

        map<int, RandomListNode *> pool;

        RandomListNode *p = head;
        RandomListNode *newHead = new RandomListNode(p->label);
        RandomListNode *q = newHead;
        pool[q->label] = q;
        while (p->next)
        {
            q->next = new RandomListNode(p->next->label);
            pool[q->next->label] = q->next;
            p = p->next;
            q = q->next;
        }

        p = head;
        q = newHead;
        while (p)
        {
            if (p->random)
                q->random = pool[p->random->label];
            p = p->next;
            q = q->next;
        }

        return newHead;
    }
};
