/*
 * Clone Graph
 * Total Accepted: 12605 Total Submissions: 56609
 *
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 * OJ's undirected graph serialization:
 *
 * Nodes are labeled uniquely.
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 *
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 *     First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 *     Second node is labeled as 1. Connect node 1 to node 2.
 *     Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 *
 * Visually, the graph looks like the following:
 *
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 *
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node == NULL)
            return NULL;

        map<int, UndirectedGraphNode *> pool;
        vector<UndirectedGraphNode *> ing;
        vector<UndirectedGraphNode *> ed;
        UndirectedGraphNode *newHead = NULL;

        ing.push_back(node);

        while (ing.size())
        {
            UndirectedGraphNode *first = ing[0];
            if (pool.find(first->label) == pool.end())
            {
                pool[first->label] = new UndirectedGraphNode(first->label);
                ed.push_back(first);
                if (newHead == NULL)
                    newHead = pool[first->label];
            }
            for (int i = 0; i < first->neighbors.size(); i++)
            {
                if (pool.find(first->neighbors[i]->label) == pool.end())
                {
                    ing.push_back(first->neighbors[i]);
                }
            }
            ing.erase(ing.begin());
        }

        for (int i = 0; i < ed.size(); i++)
        {
            UndirectedGraphNode *p = ed[i];
            UndirectedGraphNode *q = pool[p->label];
            for (int j = 0; j < p->neighbors.size(); j++)
            {
                q->neighbors.push_back(pool[p->neighbors[j]->label]);
            }
        }

        return newHead;
    }
};
