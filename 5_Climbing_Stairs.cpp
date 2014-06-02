/*
 * Climbing Stairs
 * Total Accepted: 14438 Total Submissions: 44033
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
class Solution
{
public:
    int climbStairs(int n)
    {
        // Do not use recursion. Will get "Time Limit Exceed".
        vector<int> num(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                num[i] = 1;
            if (i == 1)
                num[i] = 2;
            if (i > 1)
                num[i] = num[i - 1] + num[i - 2];
        }
        return num[n - 1];
    }
};
