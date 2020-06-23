class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        vector<bool> res;
        if (candies.empty())
            return res;

        int maxv = candies.front();

        for (auto v : candies)
        {
            if (v > maxv)
                maxv = v;
        }

        for (auto v : candies)
        {
            if (v + extraCandies >= maxv)
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};
