/*
 * Gas Station
 * Total Accepted: 12342 Total Submissions: 50635
 *
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        if (n != cost.size())
            return -1;
        if (n == 1 && gas[0] >= cost[0])
            return 0;

        for (int i = 0; i < n; i++)
        {
            gas[i] -= cost[i];
        }

        for (int i = 0; i < n; i++)
        {
            int cur = i;
            int pre = (i + n - 1) % n;
            if (gas[cur] >= 0 && gas[pre] < 0)
            {
                int it = cur;
                int sum = 0;
                while (true)
                {
                    sum += gas[it];
                    if (sum < 0)
                        break;
                    it = (it + 1) % n;
                    if (it == cur)
                    {
                        return cur;
                    }
                }
            }
        }

        return -1;
    }
};
