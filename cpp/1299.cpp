class Solution
{
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        vector<int> res;
        int maxv = -1;
        size_t n = arr.size();

        for (size_t i = 0; i < n; i++)
        {
            int v = arr[n - 1 - i];

            res.push_back(maxv);
            if (v > maxv)
                maxv = v;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
