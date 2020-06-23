class Solution
{
public:
    int minCount(vector<int>& coins)
    {
        int res = 0;

        for (auto n : coins)
            res += n / 2 + n % 2;

        return res;
    }
};
