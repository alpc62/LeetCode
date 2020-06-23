class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        vector<int> res;

        for (auto now : nums)
        {
            int s = 0;

            for (auto n : nums)
            {
                if (n < now)
                    s++;
            }

            res.push_back(s);
        }

        return res;
    }
};
