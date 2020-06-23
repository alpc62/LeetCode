class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int res = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                int x = (nums[i] - 1) * (nums[j] - 1);

                if (x > res)
                    res = x;
            }
        }

        return res;
    }
};
