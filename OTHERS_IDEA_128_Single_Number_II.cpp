/*
 * Single Number II
 * Total Accepted: 18093 Total Submissions: 54614
 *
 * Given an array of integers, every element appears three times except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        vector<int> pool(1, 1);
        while (pool[pool.size() - 1] > 0)
        {
            pool.push_back(pool[pool.size() - 1] << 1);
        }

        vector<int> count(pool.size(), 0);
        for (int i = 0; i < n; i++)
        {
            for (size_t j = 0; j < pool.size(); j++)
            {
                if (pool[j] & A[i])
                    count[j]++;
            }
        }
        int result = 0;
        for (size_t i = 0; i < count.size(); i++)
        {
            if (count[i] % 3)
                result |= pool[i];
        }
        return result;
    }
};
