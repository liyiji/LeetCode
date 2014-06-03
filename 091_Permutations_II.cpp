/*
 * Permutations II
 * Total Accepted: 9972 Total Submissions: 40471
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */
class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        vector<vector<int> > result;
        if (num.size() == 0)
            return result;
        if (num.size() == 1)
        {
            result.push_back(num);
            return result;
        }

        sort(num.begin(), num.end());
        result.push_back(num);
        while (nextPermutation(num) == false)
            result.push_back(num);

        return result;

    }

    bool nextPermutation(vector<int> &num)
    {
        bool bIsLastLoop = false;
        int index = -1;
        for (int i = num.size() - 1; i >= 1; i--)
        {
            if (num[i] > num[i - 1])
            {
                index = i - 1;
                break;
            }
        }
        if (index == -1)
        {
            bIsLastLoop = true;
        }
        else
        {
            int index2 = -1;
            for (int i = num.size() - 1; i > index; i--)
            {
                if (num[i] <= num[index] && num[i - 1] > num[index])
                {
                    index2 = i - 1;
                    break;
                }
            }

            if (index2 == -1)
                index2 = num.size() - 1;
            swap(num[index], num[index2]);
            reverse(num.begin() + index + 1, num.end());
        }
        return bIsLastLoop;
    }
};
