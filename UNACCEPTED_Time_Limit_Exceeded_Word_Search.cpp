class Solution
{
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        if (word.empty())
            return true;
        if (board.empty())
            return false;
        if (board[0].empty())
            return false;

        vector < vector<bool> > bUsed(board.size(), vector<bool>(board[0].size(), false));
        vector < pair<size_t, size_t> > route;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    route.push_back(make_pair(i, j));
                    bUsed[i][j] = true;
                    if (getSub(word, board, bUsed, 0, route))
                        return true;

                    while (route.size())
                    {
                        bUsed[route[route.size() - 1].first][route[route.size() - 1].second] = false;
                        route.resize(route.size() - 1);
                    }
                }
            }
        }
        return false;
    }

    bool getSub(const string &word, const vector<vector<char> > board, vector<vector<bool> > &bUsed, size_t startIndex, vector<pair<size_t, size_t> > &route)
    {
#ifdef liyijiDebug
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
        cout << word << " " << startIndex << endl;
        cout << "======================" << endl;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "======================" << endl;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                cout << bUsed[i][j] << " ";
            }
            cout << endl;
        }
        cout << "======================" << endl;
        for (size_t i = 0; i < route.size(); i++)
        {
            cout << route[i].first << " " << route[i].second << endl;
        }
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
#endif
        if (startIndex + 1 == word.size())
            return true;
        if (route[route.size() - 1].first != 0 && bUsed[route[route.size() - 1].first - 1][route[route.size() - 1].second] == false
                && board[route[route.size() - 1].first - 1][route[route.size() - 1].second] == word[startIndex + 1])
        {
            bUsed[route[route.size() - 1].first - 1][route[route.size() - 1].second] = true;
            route.push_back(make_pair(route[route.size() - 1].first - 1, route[route.size() - 1].second));
            if (getSub(word, board, bUsed, startIndex + 1, route))
                return true;

            while (route.size() > startIndex + 1)
            {
                bUsed[route[route.size() - 1].first][route[route.size() - 1].second] = false;
                route.resize(route.size() - 1);
            }
        }

        if (route[route.size() - 1].first != board.size() - 1 && bUsed[route[route.size() - 1].first + 1][route[route.size() - 1].second] == false
                && board[route[route.size() - 1].first + 1][route[route.size() - 1].second] == word[startIndex + 1])
        {
            bUsed[route[route.size() - 1].first + 1][route[route.size() - 1].second] = true;
            route.push_back(make_pair(route[route.size() - 1].first + 1, route[route.size() - 1].second));
            if (getSub(word, board, bUsed, startIndex + 1, route))
                return true;

            while (route.size() > startIndex + 1)
            {
                bUsed[route[route.size() - 1].first][route[route.size() - 1].second] = false;
                route.resize(route.size() - 1);
            }
        }

        if (route[route.size() - 1].second != 0 && bUsed[route[route.size() - 1].first][route[route.size() - 1].second - 1] == false
                && board[route[route.size() - 1].first][route[route.size() - 1].second - 1] == word[startIndex + 1])
        {
            bUsed[route[route.size() - 1].first][route[route.size() - 1].second - 1] = true;
            route.push_back(make_pair(route[route.size() - 1].first, route[route.size() - 1].second - 1));
            if (getSub(word, board, bUsed, startIndex + 1, route))
                return true;

            while (route.size() > startIndex + 1)
            {
                bUsed[route[route.size() - 1].first][route[route.size() - 1].second] = false;
                route.resize(route.size() - 1);
            }
        }

        if (route[route.size() - 1].second != board[0].size() - 1 && bUsed[route[route.size() - 1].first][route[route.size() - 1].second + 1] == false
                && board[route[route.size() - 1].first][route[route.size() - 1].second + 1] == word[startIndex + 1])
        {
            bUsed[route[route.size() - 1].first][route[route.size() - 1].second + 1] = true;
            route.push_back(make_pair(route[route.size() - 1].first, route[route.size() - 1].second + 1));
            if (getSub(word, board, bUsed, startIndex + 1, route))
                return true;

            while (route.size() > startIndex + 1)
            {
                bUsed[route[route.size() - 1].first][route[route.size() - 1].second] = false;
                route.resize(route.size() - 1);
            }
        }

        return false;
    }
};
