class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int a[10][10] = {0};
        if (board.size() != 9)
        {
            return false;
        }
        for (int i = 0; i < 9; i++)
        {
            if (board[i].size() != 9)
            {
                return false;
            }
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (!isValidChar(ch))
                {
                    return false;
                }
                if (ch != '.')
                {
                    int x = ch - '0';
                    if (x < 0 || x > 9)
                    {
                        return false;
                    }
                    a[i][j] = x;
                }
            }
        }
        bool show[10];
        for (int i = 0; i < 9; i++)
        {
            memset(show, 0, sizeof(show));
            for (int j = 0; j < 9; j++)
            {
                if (!a[i][j])
                {
                    continue;
                }
                if (show[a[i][j]])
                {
                    return false;
                }
                show[a[i][j]] = true;
            }
            memset(show, 0, sizeof(show));
            for (int j = 0; j < 9; j++)
            {
                if (!a[j][i])
                {
                    continue;
                }
                if (show[a[j][i]])
                {
                    return false;
                }
                show[a[j][i]] = true;
            }
        }
        for (int ii = 0; ii < 3; ii++)
        {
            for (int jj = 0; jj < 3; jj++)
            {
                int lt_x = ii * 3;
                int lt_y = jj * 3;
                memset(show, 0, sizeof(show));
                for (int dx = 0; dx < 3; dx++)
                {
                    for (int dy = 0; dy < 3; dy++)
                    {
                        int x = lt_x + dx;
                        int y = lt_y + dy;
                        if (!a[x][y])
                        {
                            continue;
                        }
                        if (show[a[x][y]])
                        {
                            return false;
                        }
                        show[a[x][y]] = true;
                    }
                }
            }
        }
        return true;
    }
private:
    bool isValidChar(const char ch)
    {
        if (ch >= '0' && ch <='9')
        {
            return true;
        }
        return ch == '.';
    }
};
