/*
 * LRU Cache
 * Total Accepted: 10384 Total Submissions: 78598
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */
class block
{
public:
    block(int k, int v)
    {
        key = k;
        val = v;
        next = NULL;
    }

    int key;
    int val;
    block *next;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        m_curUsage = 0;
        head = NULL;
        tail = NULL;
    }

    int get(int key)
    {
        int result = -1;
        block *p = head;
        block *pPre = NULL;
        while (p)
        {
            if (p->key == key)
            {
                result = p->val;
                if (p != tail)
                {
                    if (pPre)
                    {
                        pPre->next = p->next;
                        p->next = NULL;
                        tail->next = p;
                        tail = p;
                    }
                    else
                    {
                        head = p->next;
                        p->next = NULL;
                        tail->next = p;
                        tail = p;
                    }
                }
                break;
            }

            pPre = p;
            p = p->next;
        }

        return result;
    }

    void set(int key, int value)
    {
        block *p = head;
        block *pPre = NULL;
        while (p)
        {
            if (p->key == key)
            {
                p->val = value;
                if (p != tail)
                {
                    if (pPre)
                    {
                        pPre->next = p->next;
                        p->next = NULL;
                        tail->next = p;
                        tail = p;
                    }
                    else
                    {
                        head = p->next;
                        p->next = NULL;
                        tail->next = p;
                        tail = p;
                    }
                }
                break;
            }
            else
            {
                pPre = p;
                p = p->next;
            }
        }

        if (p == NULL)
        {
            if (m_curUsage < m_capacity)
            {
                block *newBlock = new block(key, value);
                if (head == NULL)
                    head = newBlock;
                if (tail)
                    tail->next = newBlock;
                tail = newBlock;
                m_curUsage++;
            }
            else
            {
                block *newBlock = new block(key, value);
                tail->next = newBlock;
                tail = newBlock;

                block *p = head;
                head = head->next;
                p->next = NULL;
                delete p;
            }
        }
    }

    int m_capacity;
    int m_curUsage;
    block *head;
    block *tail;
};
