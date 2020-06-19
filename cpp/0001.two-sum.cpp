class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        map<int, int> value2index;
        map<int, int>::iterator it;
        for (size_t i = 0; i < nums.size(); i++)
        {
            value2index[nums[i]] = i;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            it = value2index.find(target - nums[i]);
            if (it != value2index.end())
            {
                if (i == it->second)
                {
                    continue;
                }
                res.push_back(i);
                res.push_back(it->second);
                return res;
            }
        }
    }
};
