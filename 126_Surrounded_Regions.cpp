/*
 * Surrounded Regions
 * Total Accepted: 8939 Total Submissions: 65153
 *
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 */
struct pos
{
    int i;
    int j;
    pos() :
            i(0), j(0)
    {
    }

    pos(int ii, int jj)
    {
        i = ii;
        j = jj;
    }
};

class Solution
{
public:
    void solve(vector<vector<char> > &board)
    {
        if (board.size() < 3 || board[0].size() < 3)
            return;

        stack<pos> record;
        for (size_t i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
            {
                record.push(pos(i, 0));
                processSub(board, record);
            }
        }

        for (size_t i = 0; i < board.size(); i++)
        {
            if (board[i][board[0].size() - 1] == 'O')
            {
                record.push(pos(i, board[0].size() - 1));
                processSub(board, record);
            }
        }

        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (board[0][j] == 'O')
            {
                record.push(pos(0, j));
                processSub(board, record);
            }
        }

        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (board[board.size() - 1][j] == 'O')
            {
                record.push(pos(board.size() - 1, j));
                processSub(board, record);
            }
        }

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }

    void processSub(vector<vector<char> > &board, stack<pos> &record)
    {
        while (record.size())
        {
            pos tmp = record.top();
            board[tmp.i][tmp.j] = 'A';
            record.pop();
            if (tmp.i > 0)
            {
                if (board[tmp.i - 1][tmp.j] == 'O')
                    record.push(pos(tmp.i - 1, tmp.j));
            }
            if (tmp.i + 1 < board.size())
            {
                if (board[tmp.i + 1][tmp.j] == 'O')
                    record.push(pos(tmp.i + 1, tmp.j));
            }
            if (tmp.j > 0)
            {
                if (board[tmp.i][tmp.j - 1] == 'O')
                    record.push(pos(tmp.i, tmp.j - 1));
            }
            if (tmp.j + 1 < board[0].size())
            {
                if (board[tmp.i][tmp.j + 1] == 'O')
                    record.push(pos(tmp.i, tmp.j + 1));
            }
        }
    }
};
