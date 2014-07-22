/*
 * N-Queens II
 * Total Accepted: 9866 Total Submissions: 30352
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 *
 */
class Solution
{
public:
    int totalNQueens(int n)
    {
        if (n == 1)
            return 1;
        if (n <= 3)
            return 0;

        int result = 0;
        vector < pair<int, int> > positions;

        bool goAhead = true;
        while (true)
        {
            if (positions.empty())
                positions.push_back(make_pair(0, 0));

            if (goAhead)
            {
                for (int i = 0; i < n; i++)
                {
                    pair<int, int> newPos = make_pair(positions.size(), i);
                    if (ifValidAfterChange(positions, newPos))
                    {
                        positions.push_back(newPos);
                        break;
                    }

                    if (i == n - 1)
                    {
                        goAhead = false;
                    }
                }

                if (goAhead && positions.size() == n)
                {
                    result++;
                    goAhead = false;
                }
            }
            else
            {
                pair<int, int> lastPos = positions.back();
                positions.resize(positions.size() - 1);
                for (int i = lastPos.second + 1; i < n; i++)
                {
                    pair<int, int> newPos = make_pair(positions.size(), i);
                    if (ifValidAfterChange(positions, newPos))
                    {
                        goAhead = true;
                        positions.push_back(newPos);
                        break;
                    }
                }

                if (positions.empty())
                    return result;
            }
        }
    }

    bool ifValidAfterChange(const vector<pair<int, int> > &positions, pair<int, int> pos)
    {
        for (int i = 0; i < positions.size(); i++)
        {
            int tmpx = positions[i].first;
            int tmpy = positions[i].second;
            int newx = pos.first;
            int newy = pos.second;
            if (tmpx == newx || tmpy == newy || abs(tmpy - newy) == abs(tmpx - newx))
                return false;
        }
        return true;
    }
};
