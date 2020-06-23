class Solution
{
public:
    string destCity(vector<vector<string>>& paths)
    {
        map<string, int> citys;

        for (const auto& ab : paths)
        {
            citys[ab[0]]++;
            citys[ab[1]]++;
        }

        for (const auto& ab : paths)
        {
            if (citys[ab[1]] == 1)
                return ab[1];
        }

        return "";
    }
};
