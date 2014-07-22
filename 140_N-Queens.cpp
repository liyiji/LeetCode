/*
 * N-Queens
 * Total Accepted: 10911 Total Submissions: 42462
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *
 */
class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        if (n == 1)
        {
            return vector < vector<string> > (1, vector < string > (1, "Q"));
        }
        if (n <= 3)
        {
            return vector < vector<string> > (0);
        }

        vector < vector<string> > result;
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
                    vector < string > subResult(n, string(n, '.'));
                    for (int i = 0; i < n; i++)
                    {
                        subResult[i][positions[i].second] = 'Q';
                    }
                    result.push_back(subResult);
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
