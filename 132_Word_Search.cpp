/*
 * Word Search
 * Total Accepted: 11105 Total Submissions: 56682
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 *
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */
class Solution
{
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        if (board.empty())
            return false;
        if (board[0].empty())
            return false;
        if (word.empty())
            return true;

        vector < vector<bool> > flags(board.size(), vector<bool>(board[0].size(), false));
        vector < pair<int, int> > curPath;
        vector < vector<pair<int, int> > > round;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != word[0])
                    continue;

                for (int k = 0; k < curPath.size(); k++)
                {
                    flags[curPath[k].first][curPath[k].second] = false;
                }
                curPath.clear();

                curPath.push_back(make_pair(i, j));
                flags[i][j] = true;
                if (curPath.size() == word.size())
                    return true;

                if (pushToRound(i, j, board, round, flags, word) == false)
                    continue;

                while (round.size())
                {
                    while (round[round.size() - 1].size())
                    {
                        curPath.push_back(make_pair(round[round.size() - 1][round[round.size() - 1].size() - 1].first, round[round.size() - 1][round[round.size() - 1].size() - 1].second));
                        flags[curPath[curPath.size() - 1].first][curPath[curPath.size() - 1].second] = true;
                        round[round.size() - 1].resize(round[round.size() - 1].size() - 1);
                        if (curPath.size() == word.size())
                            return true;

                        if (pushToRound(curPath[curPath.size() - 1].first, curPath[curPath.size() - 1].second, board, round, flags, word) == false)
                        {
                            flags[curPath[curPath.size() - 1].first][curPath[curPath.size() - 1].second] = false;
                            curPath.resize(curPath.size() - 1);
                        }
                    }

                    flags[curPath[curPath.size() - 1].first][curPath[curPath.size() - 1].second] = false;
                    curPath.resize(curPath.size() - 1);
                    round.resize(round.size() - 1);
                }
            }
        }

        return false;
    }

    bool pushToRound(int curI, int curJ, const vector<vector<char> > &board, vector<vector<pair<int, int> > > &round, const vector<vector<bool> > &flags, const string &word)
    {
        int allI = flags.size();
        int allJ = flags[0].size();

        int wordIndex = round.size();
        vector < pair<int, int> > roundForCurPoint;
        if (curI > 0 && flags[curI - 1][curJ] == false && board[curI - 1][curJ] == word[wordIndex + 1])
            roundForCurPoint.push_back(make_pair(curI - 1, curJ));
        if (curI < allI - 1 && flags[curI + 1][curJ] == false && board[curI + 1][curJ] == word[wordIndex + 1])
            roundForCurPoint.push_back(make_pair(curI + 1, curJ));
        if (curJ > 0 && flags[curI][curJ - 1] == false && board[curI][curJ - 1] == word[wordIndex + 1])
            roundForCurPoint.push_back(make_pair(curI, curJ - 1));
        if (curJ < allJ - 1 && flags[curI][curJ + 1] == false && board[curI][curJ + 1] == word[wordIndex + 1])
            roundForCurPoint.push_back(make_pair(curI, curJ + 1));

        if (roundForCurPoint.size())
        {
            round.push_back(roundForCurPoint);
            return true;
        }
        else
        {
            return false;
        }
    }
};
