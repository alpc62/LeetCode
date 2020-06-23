class Solution
{
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int res = 0;

        for (const auto& arr : grid)
        {
            for (auto v : arr)
            {
                if (v < 0)
                    res++;
            }
        }

        return res;
    }
};
