class Solution
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        all_over = false;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch != '.')
                {
                    int x = ch - '0';
                    a[i][j] = x;
                }
            }
        }
        buildMaybe();
        while (!isFinish())
        {
            bool has_sure = false;
            int sure_x;
            int sure_y;
            for (int i = 0; !has_sure && i < 9; i++)
            {
                for (int j = 0; !has_sure && j < 9; j++)
                {
                    if (!a[i][j] && maybe[i][j].size() == 1)
                    {
                        sure_x = i;
                        sure_y = j;
                        has_sure = true;
                    }
                }
            }
            if (has_sure)
            {
                a[sure_x][sure_y] = (*(maybe[sure_x][sure_y].begin()));
                updateMaybe(sure_x, sure_y);
            }
            else
            {
                break;
            }
        }
        dfs();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = a[i][j] + '0';
            }
        }
    }
private:
    void dfs()
    {
        if (all_over)
        {
            return;
        }
        int x, y;
        bool is_find = false;
        for (int i = 0; !is_find && i < 9; i++)
        {
            for (int j = 0; !is_find && j < 9; j++)
            {
                if (!a[i][j])
                {
                    is_find = true;
                    x = i;
                    y = j;
                }
            }
        }
        set<int> temp[10][10];
        for (int ii = 0; ii < 9; ii++)
        {
            for (int jj = 0; jj < 9; jj++)
            {
                temp[ii][jj] = maybe[ii][jj];
            }
        }
        vector<int> b(maybe[x][y].begin(), maybe[x][y].end());
        vector<pair<int, int> > c;
        for (size_t idx = 0; idx < b.size(); idx++)
        {
            c.clear();
            c.push_back(make_pair(x, y));
            a[x][y] = b[idx];
            updateMaybe(x, y);
            while (isValid() && !isFinish())
            {
                bool has_sure = false;
                int sure_x;
                int sure_y;
                for (int i = 0; !has_sure && i < 9; i++)
                {
                    for (int j = 0; !has_sure && j < 9; j++)
                    {
                        if (!a[i][j] && maybe[i][j].size() == 1)
                        {
                            sure_x = i;
                            sure_y = j;
                            has_sure = true;
                        }
                    }
                }
                if (has_sure)
                {
                    c.push_back(make_pair(sure_x, sure_y));
                    a[sure_x][sure_y] = (*(maybe[sure_x][sure_y].begin()));
                    updateMaybe(sure_x, sure_y);
                }
                else
                {
                    break;
                }
            }
            if (isValid())
            {
                dfs();
                if (all_over)
                {
                    return;
                }
            }
            for (size_t i = 0; i < c.size(); i++)
            {
                a[c[i].first][c[i].second] = 0;
            }
            for (int ii = 0; ii < 9; ii++)
            {
                for (int jj = 0; jj < 9; jj++)
                {
                    maybe[ii][jj] = temp[ii][jj];
                }
            }
        }
    }
    bool isValid()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (!a[i][j] && maybe[i][j].size() == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isFinish()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (!a[i][j])
                {
                    return false;
                }
            }
        }
        all_over = true;
        return true;
    }
    void buildMaybe()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                maybe[i][j].clear();
                if (a[i][j])
                {
                    continue;
                }
                for (int k = 1; k < 10; k++)
                {
                    maybe[i][j].insert(k);
                }
            }
        }
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if (a[x][y])
                {
                    updateMaybe(x, y);
                }
            }
        }
    }
    void updateMaybe(int x, int y)
    {
        int val = a[x][y];
        for (int i = 0; i < 9; i++)
        {
            maybe[x][i].erase(val);
            maybe[i][y].erase(val);
        }
        int lt_x = (x / 3) * 3;
        int lt_y = (y / 3) * 3;
        for (int dx = 0; dx < 3; dx++)
        {
            int xx = lt_x + dx;
            for (int dy = 0; dy < 3; dy++)
            {
                int yy = lt_y + dy;
                maybe[xx][yy].erase(val);
            }
        }
    }
    int a[10][10];
    set<int> maybe[10][10];
    bool all_over;
};
