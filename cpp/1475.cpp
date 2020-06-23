class Solution
{
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        vector<int> res;

        for (auto i = 0; i < prices.size(); i++)
        {
            auto c = 0;

            for (auto j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] <= prices[i])
                {
                    c = prices[j];
                    break;
                }
            }

            res.push_back(prices[i] - c);
        }

        return res;
    }
};
