class Solution
{
public:
    int oddCells(int n, int m, vector<vector<int>>& indices)
    {
        vector<int> row_count;
        vector<int> col_count;

        row_count.resize(n);
        col_count.resize(m);

        for (auto ab : indices)
        {
            row_count[ab[0]]++;
            col_count[ab[1]]++;
        }

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((row_count[i] + col_count[j]) % 2)
                    res++;
            }
        }

        return res;
    }
};
