/*
 * Combinations
 * Total Accepted: 12251 Total Submissions: 40872
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 */
class Solution
{
public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > result;
        unsigned long long lineCount = combineCounts(n, k);
        result.resize(lineCount);
        for (unsigned long long i = 0; i < lineCount; i++)
        {
            result[i].resize(k);
        }

        fill(result, n, 1, n, k, 0, 0);

        return result;
    }

    void fill(vector<vector<int> >& vec, int n, int min, int max, int k, int startLine, int startPos)
    {
        // max == min + n - 1; (max - min + 1 == n)
        // n is all, k is k, [startLine, startPos] is the start write position of vec.
        if (k == 1)
        {
            for (int i = min; i <= max; i++)
            {
                vec[startLine + i - min][startPos] = i;
            }
        }
        else
        {
            int sum = 0;
            for (int i = 1; i <= n - k + 1; i++)
            {
                unsigned long long ni = combineCounts(n - i, k - 1);
                for (unsigned long long j = 0; j < ni; j++)
                {
                    vec[startLine + sum + j][startPos] = min + i - 1;
                }

                int newN = n - i;
                int newMin = min + i;
                int newK = k - 1;
                int newStartLine = startLine + sum;
                int newStartPos = startPos + 1;

                fill(vec, newN, newMin, max, newK, newStartLine, newStartPos);
                sum += ni;
            }
        }
    }

    unsigned long long combineCounts(unsigned long long n, unsigned long long k)
    {
        unsigned long long sum = jieCheng(n) / (jieCheng(n - k) * jieCheng(k));
        return sum;
    }

    unsigned long long jieCheng(unsigned long long n)
    {
        if (n < 0)
            return 0;
        if (n == 0 || n == 1)
            return 1;
        return n * jieCheng(n - 1);
    }
};
