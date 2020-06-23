class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        vector<int> res;

        if (n == 0)
            return res;

        int m = 0;
        for (int i = 0; i < n; i++)
            m = m * 10 + 9;

        for (int i = 0; i < m; i++)
            res.push_back(i + 1);

        return res;
    }
};
