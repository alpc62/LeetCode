class Solution
{
public:
    vector<int> runningSum(vector<int>& nums)
    {
        vector<int> res;
        int s = 0;

        for (auto x : nums)
        {
            s += x;
            res.push_back(s);
        }

        return res;
    }
};
