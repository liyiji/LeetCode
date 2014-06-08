/*
 * Surrounded Regions
 * Total Accepted: 8082 Total Submissions: 59223
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
    int x;
    int y;
    pos() :
            x(0), y(0)
    {
    }

    pos(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};

class Solution
{
public:
    void solve(vector<vector<char> > &board)
    {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        if (n == 0)
            return;

        if (m <= 2 || n <= 2)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    board[i][j] = 'X';
                }
            }
            return;
        }

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (board[i][j] == 'O')
                {
                    // calc range, judge whether is side, if not side, change 'O' to 'X'. if side, change 'O' to 'S'
                    func(board, i, j);
                }
            }
        }

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (board[i][j] == 'S')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void func(vector<vector<char> > &board, int startI, int startJ)
    {
        if (board[startI][startJ] != 'O')
            return;

        vector<pos> ap; // alreadyProcessed
        vector<pos> wp; // willProcess
        wp.push_back(pos(startI, startJ));
        while (wp.size())
        {
            int n = wp.size();
            for (int i = 0; i < n; i++)
            {
                if (board[wp[i].x][wp[i].y] != 'O')
                    continue;

                if (wp[i].x + 1 < board.size() && wp[i].y + 1 < board[0].size() && board[wp[i].x + 1][wp[i].y + 1] == 'O')
                {
                    wp.push_back(pos(wp[i].x + 1, wp[i].y + 1));
                }
                if (wp[i].x + 1 < board.size() && wp[i].y - 1 >= 0 && board[wp[i].x + 1][wp[i].y - 1] == 'O')
                {
                    wp.push_back(pos(wp[i].x + 1, wp[i].y - 1));
                }
                if (wp[i].x - 1 >= 0 && wp[i].y + 1 < board[0].size() && board[wp[i].x - 1][wp[i].y + 1] == 'O')
                {
                    wp.push_back(pos(wp[i].x - 1, wp[i].y + 1));
                }
                if (wp[i].x - 1 >= 0 && wp[i].y - 1 >= 0 && board[wp[i].x - 1][wp[i].y - 1] == 'O')
                {
                    wp.push_back(pos(wp[i].x - 1, wp[i].y - 1));
                }
                ap.push_back(wp[i]);
            }
            wp.erase(wp.begin(), wp.begin() + n);
        }

        bool bSide = false;
        for (int i = 0; i < ap.size(); i++)
        {
            if (isSide(ap[i].x, ap[i].y, board))
            {
                bSide = true;
                break;
            }
        }

        for (int i = 0; i < ap.size(); i++)
        {
            board[ap[i].x][ap[i].y] = (bSide ? 'S' : 'X');
        }
    }

    bool isSide(int i, int j, const vector<vector<char> > &board)
    {
        if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1)
        {
            return true;
        }
        return false;
    }
};
