/*
 * Sudoku Solver
 * Total Accepted: 9197 Total Submissions: 44191
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 *
 * A sudoku puzzle...
 *
 *
 * ...and its solution numbers marked in red.
 */
class Solution
{
public:
    // Tips: DO NOT have to care about Time Complexity
    // Tips: Loop parameter is 0-8, numbers are 1-9
    // Tips: Numbers in board should be char, which char(0) == int(48)
    void solveSudoku(vector<vector<char> > &board)
    {
        vector < pair<pair<int, int>, vector<int> > > possibles;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    vector<int> used;
                    for (int k = 0; k < 9; k++)
                    {
                        if (board[k][j] != '.')
                            used.push_back(toInt(board[k][j]));
                    }
                    for (int k = 0; k < 9; k++)
                    {
                        if (board[i][k] != '.')
                            used.push_back(toInt(board[i][k]));
                    }
                    for (int k = i / 3 * 3; k < (i / 3 + 1) * 3; k++)
                    {
                        for (int l = j / 3 * 3; l < (j / 3 + 1) * 3; l++)
                        {
                            if (board[k][l] != '.')
                                used.push_back(toInt(board[k][l]));
                        }
                    }
                    sort(used.begin(), used.end());
                    used.resize(unique(used.begin(), used.end()) - used.begin());
                    possibles.push_back(make_pair(make_pair(i, j), getUnused(used)));
                }
            }
        }

        stack<int> indices;
        bool goAhead = true;
        while (indices.size() < possibles.size())
        {
            if (goAhead)
            {
                bool bFound = false;
                for (int i = 0; i < possibles[indices.size()].second.size(); i++)
                {
                    int tmp = indices.size();
                    if (ifValidAfterChange(board, possibles[tmp].first, possibles[tmp].second[i]))
                    {
                        bFound = true;
                        board[possibles[tmp].first.first][possibles[tmp].first.second] = toChar(possibles[tmp].second[i]);
                        indices.push(i);
                        break;
                    }
                }

                if (bFound == false)
                {
                    goAhead = false;
                }
            }
            else
            {
                int preIndex = indices.top();
                int tmp = indices.size();
                board[possibles[tmp].first.first][possibles[tmp].first.second] = '.';
                indices.pop();

                bool bFound = false;
                for (int i = preIndex; i < possibles[indices.size()].second.size(); i++)
                {
                    tmp = indices.size();
                    if (ifValidAfterChange(board, possibles[tmp].first, possibles[tmp].second[i]))
                    {
                        bFound = true;
                        board[possibles[tmp].first.first][possibles[tmp].first.second] = toChar(possibles[tmp].second[i]);
                        indices.push(i);
                        break;
                    }
                }

                if (bFound)
                {
                    goAhead = true;
                }
            }
        }
    }

private:
    vector<int> getUnused(const vector<int> &used)
    {
        vector<int> unused;
        int j = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (j == used.size())
            {
                unused.push_back(i);
            }
            else if (i == used[j])
            {
                j++;
            }
            else
            {
                unused.push_back(i);
            }
        }
        return unused;
    }

    bool ifValidAfterChange(const vector<vector<char> > &board, pair<int, int> pos, int val)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[k][pos.second] == toChar(val))
                return false;
        }
        for (int k = 0; k < 9; k++)
        {
            if (board[pos.first][k] == toChar(val))
                return false;
        }
        for (int k = pos.first / 3 * 3; k < (pos.first / 3 + 1) * 3; k++)
        {
            for (int l = pos.second / 3 * 3; l < (pos.second / 3 + 1) * 3; l++)
            {
                if (board[k][l] == toChar(val))
                    return false;
            }
        }

        return true;
    }

    int toInt(char num)
    {
        return num - 48;
    }

    char toChar(int num)
    {
        return num + 48;
    }
};
