class Solution
{
public:
    int heightChecker(vector<int>& heights)
    {
        int res = 0;
        vector<int> a = heights;

        sort(a.begin(), a.end());
        for (auto i = 0; i < a.size(); i++)
        {
            if (a[i] != heights[i])
                res++;
        }

        return res;
    }
};
