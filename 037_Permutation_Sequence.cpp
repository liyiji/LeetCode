/*
 * Permutation Sequence
 * Total Accepted: 7772 Total Submissions: 36165
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 *     "123"
 *     "132"
 *     "213"
 *     "231"
 *     "312"
 *     "321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> input(n);
        for (int i = 0; i < n; i++)
        {
            input[i] = i + 1;
        }
        string result = getSub(input, k - 1);
        return result;
    }

    string getSub(vector<int> &input, int ith)
    {
        string result;
        if (input.size() == 1)
        {
            result.push_back(input[0] + '0');
            return result;
        }
        int n = input.size();
        int subPCount = pCount(n - 1);
        int t = ith / subPCount;
        result.push_back(input[t] + '0');
        input.erase(input.begin() + t);
        result.append(getSub(input, ith % subPCount));
        return result;
    }

    int pCount(int k)
    {
        int result = 1;
        for (int i = 1; i <= k; i++)
        {
            result *= i;
        }
        return result;
    }
};
