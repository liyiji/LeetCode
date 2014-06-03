/*
 * Subsets
 * Total Accepted: 13373 Total Submissions: 48941
 *
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 *
 *     Elements in a subset must be in non-descending order.
 *     The solution set must not contain duplicate subsets.
 *
 * For example,
 * If S = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */
class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        result.resize(pow(2, S.size()));

        int sum = 1;
        for (size_t i = 1; i <= S.size(); i++)
        {
            vector<vector<int> > tmp = combine(S, i);
            {
                for (size_t j = 0; j < tmp.size(); j++)
                {
                    result[j + sum].resize(i);
                    for (size_t k = 0; k < i; k++)
                    {
                        result[j + sum][k] = tmp[j][k];
                    }
                }
            }
            sum += tmp.size();
        }

        return result;
    }

    vector<vector<int> > combine(vector<int> s, int k)
    {
        vector<vector<int> > result;
        unsigned long long lineCount = combineCounts(s.size(), k);
        result.resize(lineCount);
        for (unsigned long long i = 0; i < lineCount; i++)
        {
            result[i].resize(k);
        }

        fill(result, s, 0, s.size() - 1, k, 0, 0);

        return result;
    }

    void fill(vector<vector<int> >& vec, vector<int> &s, int min, int max, int k, int startLine, int startPos)
    {
        // n is all, k is k, [startLine, startPos] is the start write position of vec.
        int n = max - min + 1;

        if (k == 1)
        {
            for (int i = min; i <= max; i++)
            {
                vec[startLine + i - min][startPos] = s[i];
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
                    vec[startLine + sum + j][startPos] = s[min + i - 1];
                }
                int newN = n - i;
                int newMin = min + i;
                int newK = k - 1;
                int newStartLine = startLine + sum;
                int newStartPos = startPos + 1;

                fill(vec, s, newMin, max, newK, newStartLine, newStartPos);
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
