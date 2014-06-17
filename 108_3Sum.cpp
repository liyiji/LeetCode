/*
 * 3Sum
 * Total Accepted: 15146 Total Submissions: 92115
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 *     Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *     The solution set must not contain duplicate triplets.
 *
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 *
 */
class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<int> small;
        vector<int> big;
        int zeroCount = 0;
        for (size_t i = 0; i < num.size(); i++)
        {
            if (num[i] < 0)
                small.push_back(num[i]);
            else if (num[i] > 0)
                big.push_back(num[i]);
            else
                zeroCount++;
        }
        reverse(small.begin(), small.end());

        vector < vector<int> > result;
        size_t originalSize = result.size();

        if (zeroCount >= 3)
        {
            result.resize(originalSize + 1);
            result[result.size() - 1].push_back(0);
            result[result.size() - 1].push_back(0);
            result[result.size() - 1].push_back(0);
        }
        if (zeroCount)
        {
            vector < vector<int> > oneAndOne = getOneAndOne(small, big);
            originalSize = result.size();
            result.resize(originalSize + oneAndOne.size());
            for (size_t i = 0; i < oneAndOne.size(); i++)
            {
                for (size_t j = 0; j < oneAndOne[i].size(); j++)
                    result[originalSize + i].push_back(oneAndOne[i][j]);
            }
        }

        vector < vector<int> > twoAndOne = getTwoAndOne(small, big);
        originalSize = result.size();
        result.resize(originalSize + twoAndOne.size());
        for (size_t i = 0; i < twoAndOne.size(); i++)
        {
            for (size_t j = 0; j < twoAndOne[i].size(); j++)
                result[originalSize + i].push_back(twoAndOne[i][j]);
        }

        vector < vector<int> > oneAndTwo = getOneAndTwo(small, big);
        originalSize = result.size();
        result.resize(originalSize + oneAndTwo.size());
        for (size_t i = 0; i < oneAndTwo.size(); i++)
        {
            for (size_t j = 0; j < oneAndTwo[i].size(); j++)
                result[originalSize + i].push_back(oneAndTwo[i][j]);
        }

        return result;
    }

    vector<vector<int> > getOneAndOne(const vector<int> &small, const vector<int> &big)
    {
        vector < vector<int> > result;
        if (small.empty() || big.empty())
            return result;

        size_t iSmall = 0;
        size_t iBig = 0;
        while (iSmall < small.size() && iBig < big.size())
        {
            if (small[iSmall] + big[iBig] == 0)
            {
                result.resize(result.size() + 1);
                result[result.size() - 1].push_back(small[iSmall]);
                result[result.size() - 1].push_back(0);
                result[result.size() - 1].push_back(big[iBig]);

                size_t iSmallpp = iSmall + 1;
                while (iSmallpp < small.size())
                {
                    if (small[iSmallpp] == small[iSmall])
                        iSmallpp++;
                    else
                        break;
                }
                if (iSmallpp == small.size())
                    break;
                else
                    iSmall = iSmallpp;

                size_t iBigpp = iBig + 1;
                while (iBigpp < big.size())
                {
                    if (big[iBigpp] == big[iBig])
                        iBigpp++;
                    else
                        break;
                }
                if (iBigpp == big.size())
                    break;
                else
                    iBig = iBigpp;
            }
            else if (small[iSmall] + big[iBig] < 0)
            {
                iBig++;
            }
            else if (small[iSmall] + big[iBig] > 0)
            {
                iSmall++;
            }
        }

        return result;
    }

    vector<vector<int> > getTwoAndOne(const vector<int> &small, const vector<int> &big)
    {
        // two big and one small
        vector < vector<int> > result;
        if (small.empty() || big.empty())
            return result;

        size_t iSmall = 0;
        size_t iBig1 = 0;
        size_t iBig2 = 0;
        while (iSmall < small.size())
        {
            for (iBig1 = 0; iBig1 + 1 < big.size(); iBig1++)
            {
                if (big[iBig1] + big[iBig1] + small[iSmall] > 0)
                    break;
                for (iBig2 = iBig1 + 1; iBig2 < big.size(); iBig2++)
                {
                    int subResult = big[iBig1] + big[iBig2] + small[iSmall];
                    if (subResult == 0)
                    {
                        if (result.size() == 0 || small[iSmall] != result[result.size() - 1][0] || big[iBig1] != result[result.size() - 1][1] || big[iBig2] != result[result.size() - 1][2])
                        {
                            result.resize(result.size() + 1);
                            result[result.size() - 1].push_back(small[iSmall]);
                            result[result.size() - 1].push_back(big[iBig1]);
                            result[result.size() - 1].push_back(big[iBig2]);
                        }
                    }
                    else if (subResult > 0)
                    {
                        break;
                    }
                    else if (subResult < 0)
                    {
                        continue;
                    }
                }
            }

            size_t iSmallpp = iSmall + 1;
            while (iSmallpp < small.size())
            {
                if (small[iSmallpp] == small[iSmall])
                    iSmallpp++;
                else
                    break;
            }
            iSmall = iSmallpp;
        }

        return result;
    }

    vector<vector<int> > getOneAndTwo(const vector<int> &small, const vector<int> &big)
    {
        // one big and two small
        vector < vector<int> > result;
        if (small.empty() || big.empty())
            return result;

        size_t iSmall1 = 0;
        size_t iSmall2 = 0;
        size_t iBig = 0;
        while (iBig < big.size())
        {
            for (iSmall1 = 0; iSmall1 + 1 < small.size(); iSmall1++)
            {
                if (small[iSmall1] + small[iSmall1] + big[iBig] < 0)
                    break;
                for (iSmall2 = iSmall1 + 1; iSmall2 < small.size(); iSmall2++)
                {
                    int subResult = small[iSmall1] + small[iSmall2] + big[iBig];
                    if (subResult == 0)
                    {
                        if (result.size() == 0 || small[iSmall2] != result[result.size() - 1][0] || small[iSmall1] != result[result.size() - 1][1] || big[iBig] != result[result.size() - 1][2])
                        {
                            result.resize(result.size() + 1);
                            result[result.size() - 1].push_back(small[iSmall2]);
                            result[result.size() - 1].push_back(small[iSmall1]);
                            result[result.size() - 1].push_back(big[iBig]);
                        }
                    }
                    else if (subResult < 0)
                    {
                        break;
                    }
                    else if (subResult > 0)
                    {
                        continue;
                    }
                }
            }

            size_t iBigpp = iBig + 1;
            while (iBigpp < big.size())
            {
                if (big[iBigpp] == big[iBig])
                    iBigpp++;
                else
                    break;
            }
            iBig = iBigpp;
        }

        return result;
    }
};
