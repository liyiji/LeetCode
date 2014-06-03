/*
 * Valid Sudoku
 * Total Accepted: 8309 Total Submissions: 30200
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */
class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        return (isValidLines(board) && isValidRows(board) && isValidBlocks(board));
    }

    bool isValidLines(vector<vector<char> > &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (P(board[i][j]))
                    continue;

                for (int k = j + 1; k < 9; k++)
                {
                    if (P(board[i][k]))
                        continue;

                    if (board[i][j] == board[i][k])
                        return false;
                }
            }
        }
        return true;
    }

    bool isValidRows(vector<vector<char> > &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (P(board[j][i]))
                    continue;

                for (int k = j + 1; k < 9; k++)
                {
                    if (P(board[k][i]))
                        continue;

                    if (board[j][i] == board[k][i])
                        return false;
                }
            }
        }
        return true;
    }

    bool isValidBlocks(vector<vector<char> > &b)
    {
        for (int i = 0; i < 3; i++)
        {
            swap(b[i * 3 + 1][0], b[i * 3][3]);
            swap(b[i * 3 + 1][1], b[i * 3][4]);
            swap(b[i * 3 + 1][2], b[i * 3][5]);

            swap(b[i * 3 + 2][0], b[i * 3][6]);
            swap(b[i * 3 + 2][1], b[i * 3][7]);
            swap(b[i * 3 + 2][2], b[i * 3][8]);

            swap(b[i * 3 + 2][3], b[i * 3 + 1][6]);
            swap(b[i * 3 + 2][4], b[i * 3 + 1][7]);
            swap(b[i * 3 + 2][5], b[i * 3 + 1][8]);
        }
        return isValidLines(b);
    }

    bool P(char a)
    {
        if (a == '.')
            return true;
        return false;
    }
};
